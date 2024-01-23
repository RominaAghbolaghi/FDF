/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:15:38 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/12 10:35:04 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include "../includes/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "../includes/gnl/get_next_line.h"
# include "../includes/Libft/libft.h"
# include "../includes/printf/ft_printf.h"

# define MLX_ERROR 1
# define BASE "0123456789ABCDEF"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080   
//2560x1440

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_base_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endianess;
}				t_img;

typedef struct s_matrix
{
	int		rows;
	int		columns;
	double	**data;
}				t_matrix;

typedef struct s_array
{
	double	x;
	double	y;
	double	z;
	int		color;

	int		x_screen;
	int		y_screen;
}				t_array;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_array	**fdf_file;
	t_img	img;

	int		width;
	int		length;

	double	scale;
	double	z_scale;
	double	zoom;

	double	roll;
	double	pitch;
	double	yaw;
}			t_data;

int			ft_atoi_base(char *str, char *base);
int			handle_keyrelease(int keycode, t_data *data);
int			handle_keypress(int keycode, t_data *data);
int			handle_mouse_release(int button, int x, int y, t_data *data);
int			close_window(t_data *data);
int			handle_no_event(void *param);
int			find_length_width(int fd, t_data *data);
int			encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue);
int			paint_black_win(t_data *data);
int			draw(t_data *data);
int			img_generation(t_data data);

void		pix_addr_and_draw(t_data *data, int length, int width);
void		update_parameters(t_data *data, int keycode);
void		put_to_upper(char *str);
void		data_init(t_data *data);
void		parsing(int fd, t_data *data);
void		set_axes_values(t_data *data, t_array *fdf_file, char **tab, int y);
void		img_pix_addr(t_img *img, int x, int y, int color);
void		execute(t_array *start_pixel, t_array *end, t_img img);
void		drawline(t_array *start_pixel, t_array *end, t_img img);
void		re_draw(t_data *data);
void		rotate(t_data *data);
void		screen_axes(t_array *fdf_file, t_matrix rotate_matrix);
void		zoom(t_data *data, double zoom);
void		scale_z(t_data *data, double z_scale);

t_matrix	multiply_two_matrix(t_matrix A, t_matrix B);
t_matrix	rotate_matrix_yaw(double angle);
t_matrix	rotate_matrix_pitch(double angle);
t_matrix	rotate_matrix_roll(double angle);
t_matrix	rotate_init(double roll, double pitch, double yaw);

void		free_data(t_data data);
void		free_matrix(t_matrix A);
void		free_malloc(char **ptr_ptr);

#endif
