/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:57:10 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/09 13:11:06 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

int	find_length_width(int fd, t_data *data)
{
	char	*line;

	data->width = 0;
	data->length = 0;
	if (fd < 0)
		return (perror(NULL), -1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	data->width = ft_size_word(line, ' ');
	while (ft_strlen(line) > 0)
	{
		data->length++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (data->width <= 0 || data->length == 0)
		return (close(fd), -1);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (perror(NULL), -1);
	}
	else
		return (ft_printf("invalid number of arguments\n"), -1);
	if (find_length_width(fd, &data) < 0)
		return (ft_printf("empty file\n"), -1);
	fd = open(argv[1], O_RDONLY);
	parsing(fd, &data);
	rotate(&data);
	img_generation(data);
	free_data(data);
	return (0);
}
