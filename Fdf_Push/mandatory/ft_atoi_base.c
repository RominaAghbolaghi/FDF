/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:17:01 by shabibol          #+#    #+#             */
/*   Updated: 2023/04/28 11:47:47 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	ft_is_whitespace(char c)
{
	int		i;
	char	*ws;

	i = 0;
	ws = "\f\t\n\r\v ";
	while (c != ws[i])
	{
		if (ws[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+' || ft_is_whitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_pos_in_base(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	signe;
	int	base_len;

	i = 0;
	nb = 0;
	signe = 1;
	base_len = ft_strlen(base);
	if (ft_is_valid_base(base))
	{
		while (ft_is_whitespace(str[i]) && str[i])
			i++;
		while (str[i] == '0' || str[i] == 'x' || str[i] == 'X')
			i++;
		while ((str[i] == '+' || str[i] == '-') && str[i])
			if (str[i++] == '-')
				signe *= -1;
		while (ft_pos_in_base(str[i], base) != -1 && str[i])
			nb = nb * base_len + ft_pos_in_base(str[i++], base);
		return (nb * signe);
	}
	return (0);
}
