/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:06:33 by rmohamma          #+#    #+#             */
/*   Updated: 2023/05/11 13:03:19 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

void	execute(t_array *start_line, t_array *end_line, t_img img)
{
	double	x;
	double	y;
	double	color;
	double	max;

	x = start_line->x_screen;
	y = start_line->y_screen;
	if ((end_line->y_screen - start_line->y_screen)
		> (end_line->x_screen - start_line->x_screen))
		max = end_line->y_screen - start_line->y_screen;
	else
		max = end_line->x_screen - start_line->x_screen;
	color = start_line->color;
	while (x < end_line->x_screen - 1)
	{
		x = x + ((end_line->x_screen - start_line->x_screen) / max);
		y = y + ((end_line->y_screen - start_line->y_screen) / max);
		color = color + ((end_line->color - start_line->color) / max);
		img_pix_addr(&img, x, y, color);
	}
	return ;
}

int	paint_black_win(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			img_pix_addr(&data->img, x, y, encode_rgb(0, 0, 0));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	return (0);
}

void	re_draw(t_data *data)
{
	paint_black_win(data);
	rotate(data);
	draw(data);
	return ;
}

void	update_parameters(t_data *data, int keycode)
{
	if (keycode == 4 || keycode == 5)
		zoom(data, data->zoom);
	if (keycode == XK_Up)
	{
		data->z_scale = 2;
		scale_z(data, data->z_scale);
	}
	if (keycode == XK_Down)
	{
		data->z_scale = 0.8;
		scale_z(data, data->z_scale);
	}
	if (keycode == XK_c)
		data->roll = data->roll + 0.05;
	if (keycode == XK_z)
		data->roll = data->roll - 0.05;
	if (keycode == XK_u)
		data->pitch = data->pitch + 0.05;
	if (keycode == XK_t)
		data->pitch = data->pitch - 0.05;
	if (keycode == XK_x)
		data->yaw = data->yaw + 0.05;
	if (keycode == XK_a)
		data->yaw = data->yaw - 0.05;
	re_draw(data);
}
