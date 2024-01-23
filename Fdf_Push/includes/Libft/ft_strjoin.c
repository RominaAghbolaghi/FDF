/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:26:21 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/05 12:21:30 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		k;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (0);
	dst = (char *) malloc (sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (0);
	j = 0;
	k = 0;
	while (s1[j] != '\0')
	{
		dst[j] = s1[j];
		j++;
	}
	while (s2[k] != '\0')
		dst[j++] = s2[k++];
	dst[j] = '\0';
	return (dst);
}
