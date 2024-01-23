/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:32:12 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/05 12:21:26 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *lst, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (lst != NULL && f != NULL)
	{
		while (lst[i] != '\0')
		{
			(*f)(i, &lst[i]);
			i++;
		}
	}
}
