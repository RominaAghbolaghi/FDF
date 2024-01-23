/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:36:33 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/05 11:23:15 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	free_matrix(t_matrix A)
{
	int	i;

	i = A.rows;
	while (i > 0)
	{
		i--;
		free(A.data[i]);
	}
	free(A.data);
	return ;
}

void	free_data(t_data data)
{
	int	i;

	i = data.length;
	while (i > 0)
	{
		i--;
		free(data.fdf_file[i]);
	}
	free(data.fdf_file);
	return ;
}

char	**glob_free(char **dst)
{
	int	i;

	i = 0;
	while (dst && dst[i])
		i++;
	while (i > 0)
	{
		i--;
		free((void *)dst[i]);
	}
	free (dst);
	return (NULL);
}
