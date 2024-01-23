/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:18:03 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/11 12:01:15 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	put_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return ;
}

void	set_axes_values(t_data *data, t_array *fdf_file, char **elements,
		int length)
{
	int		width;
	char	**content;

	content = NULL;
	width = 0;
	while (elements[width] && width < data->width)
	{
		fdf_file[width].x = width * data->scale
			- (data->width * data->scale / 2);
		fdf_file[width].y = length * data->scale
			- (data->length * data->scale / 2);
		content = ft_split(elements[width], ',');
		fdf_file[width].z = ft_atoi(content[0]) * 2;
		if (!content[1] && fdf_file[width].z == 0)
			fdf_file[width].color = encode_rgb(255, 255, 255);
		else if (!content[1] && fdf_file[width].z != 0)
			fdf_file[width].color = encode_rgb(255, 0, 255);
		else if (content[1])
		{
			put_to_upper(content[1]);
			fdf_file[width].color = ft_atoi_base(content[1], BASE);
		}
		glob_free(content);
		width++;
	}
}

void	data_init(t_data *data)
{
	data->roll = 1.05;
	data->pitch = 0.5;
	data->yaw = -0.25;
	data->scale = fmin(((WIN_HEIGHT / data->length) / 2.5),
			((WIN_WIDTH / data->width) / 2.5));
	return ;
}

void	parsing(int fd, t_data *data)
{
	char	*line;
	char	**elements;
	int		length;

	if (fd < 0)
		return ;
	length = 0;
	data_init(data);
	data->fdf_file = (t_array **) malloc((sizeof(t_array *))*(data->length));
	line = get_next_line(fd);
	while (ft_strlen(line) > 0)
	{
		elements = ft_split(line, ' ');
		data->fdf_file[length] = (t_array *)malloc(sizeof(t_array)
				* (data->width));
		set_axes_values(data, data->fdf_file[length], elements, length);
		glob_free(elements);
		free(line);
		line = get_next_line(fd);
		length++;
	}
	free(line);
	close(fd);
}
