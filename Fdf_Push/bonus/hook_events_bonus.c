/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:03:17 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/11 13:06:42 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

int	handle_no_event(void *param)
{
	(void)param;
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		data->zoom = 1.1;
		update_parameters(data, button);
	}
	if (button == 5)
	{
		data->zoom = 0.9;
		update_parameters(data, button);
	}
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else if (keycode == XK_Up || keycode == XK_Down || keycode == XK_z
		|| keycode == XK_c || keycode == XK_t || keycode == XK_u
		|| keycode == XK_x || keycode == XK_a)
		update_parameters(data, keycode);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
