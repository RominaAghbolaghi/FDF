/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:36:33 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/12 10:31:23 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf_bonus.h"

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

void	free_malloc(char **ptr_ptr)
{
	int	i;

	i = 0;
	while (ptr_ptr[i])
	{
		free(ptr_ptr[i]);
		i++;
	}
	free(ptr_ptr);
}
