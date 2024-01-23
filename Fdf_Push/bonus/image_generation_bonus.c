/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_generation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:09:36 by rmohamma          #+#    #+#             */
/*   Updated: 2023/05/11 16:05:34 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

void	drawline(t_array *start_line, t_array *end_line, t_img img)
{
	if (end_line->x_screen < start_line->x_screen)
		execute(end_line, start_line, img);
	else
		execute(start_line, end_line, img);
	return ;
}

void	img_pix_addr(t_img *img, int x_screen, int y_screen, int color)
{
	char	*pixel_new_addr;
	int		msb;

	if (x_screen > 0 && x_screen < WIN_WIDTH && y_screen > 0
		&& y_screen < WIN_HEIGHT)
	{
		msb = img->bits_per_pixel - 8;
		pixel_new_addr = img->pixel_base_addr + (y_screen
				* img->size_line + x_screen
				* (img->bits_per_pixel / 8));
		while (msb >= 0)
		{
			if (img->endianess != 0)
				*pixel_new_addr++ = (color >> msb) & 0xFF;
			else
				*pixel_new_addr++ = (color >> (img->bits_per_pixel - 8 - msb))
					& 0xFF;
			msb -= 8;
		}
	}
	return ;
}

void	pix_addr_and_draw(t_data *data, int length, int width)
{
	img_pix_addr(&data->img, data->fdf_file[length][width].x_screen,
		data->fdf_file[length][width].y_screen,
		data->fdf_file[length][width].color);
	if (length != data->length - 1)
		drawline(&data->fdf_file[length][width],
			&data->fdf_file[length + 1][width], data->img);
	if (width != data->width - 1)
		drawline(&data->fdf_file[length][width],
			&data->fdf_file[length][width + 1], data->img);
}

int	draw(t_data *data)
{
	int	length;
	int	width;

	length = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (length < data->length)
	{
		width = 0;
		while (width < data->width)
		{
			pix_addr_and_draw(data, length, width);
			width++;
		}
		length++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr,
		0, 0);
	return (0);
}

int	img_generation(t_data data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"My FDF Project");
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.pixel_base_addr = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pixel, &data.img.size_line,
			&data.img.endianess);
	draw(&data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, NULL);
	mlx_mouse_hook(data.win_ptr, &handle_mouse_release, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 33, 131072, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
