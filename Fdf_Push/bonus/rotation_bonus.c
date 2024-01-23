/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:58:20 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/11 11:35:10 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

void	zoom(t_data *data, double zoom)
{
	int			width;
	int			length;

	length = 0;
	while (length < data->length)
	{
		width = 0;
		while (width < data->width)
		{
			data->fdf_file[length][width].x = data->fdf_file[length][width].x
				* zoom;
			data->fdf_file[length][width].y = data->fdf_file[length][width].y
				* zoom;
			data->fdf_file[length][width].z = data->fdf_file[length][width].z
				* zoom;
			width++;
		}
		length++;
	}
	return ;
}

void	scale_z(t_data *data, double z_scale)
{
	int			width;
	int			length;

	length = 0;
	while (length < data->length)
	{
		width = 0;
		while (width < data->width)
		{
			data->fdf_file[length][width].z = data->fdf_file[length][width].z
				* z_scale;
			width++;
		}
		length++;
	}
	return ;
}

void	screen_axes(t_array *fdf_file, t_matrix rotate_matrix)
{
	double		fdf_axes[3][1];
	double		rotated_axes[3][1];
	int			i;

	fdf_axes[0][0] = (double) fdf_file->x;
	fdf_axes[1][0] = (double) fdf_file->y;
	fdf_axes[2][0] = (double) fdf_file->z;
	i = 0;
	while (i < rotate_matrix.rows)
	{
		rotated_axes[i][0] = fdf_axes[0][0] * rotate_matrix.data[i][0]
			+ fdf_axes[1][0] * rotate_matrix.data[i][1]
			+ fdf_axes[2][0] * rotate_matrix.data[i][2];
		i++;
	}
	fdf_file->x_screen = (int) rotated_axes[0][0] + WIN_WIDTH / 2;
	fdf_file->y_screen = (int) rotated_axes[1][0] + WIN_HEIGHT / 2;
}

void	rotate(t_data *data)
{
	int			width;
	int			length;
	t_matrix	rotate_matrix;

	rotate_matrix = rotate_init(data->roll, data->pitch, data->yaw);
	length = 0;
	while (length < data->length)
	{
		width = 0;
		while (width < data->width)
		{
			screen_axes(&data->fdf_file[length][width], rotate_matrix);
			width++;
		}
		length++;
	}
	free_matrix(rotate_matrix);
	return ;
}
