/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:15:51 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/05 12:23:23 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_cut(t_print *tab, char *str)
{
	char	*dest;
	int		size;
	int		i;

	size = ft_pf_strlen(str);
	i = 0;
	if (tab->pnt == 1 && tab->precision == 0)
		size = 0;
	if (tab->pnt == 1 && tab->precision != 0)
	{
		if ((tab->precision) < size)
			size = tab->precision;
	}
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (str && i != size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_str_multi_padding_left(char *src, char *padding)
{
	char	*res;
	int		i;
	int		width;

	width = ft_pf_strlen(src) + ft_pf_strlen(padding);
	i = 0;
	res = (char *)malloc(sizeof(char) *(width + 1));
	if (!res || !padding)
		return (NULL);
	while (padding[i] != '\0')
	{
		res[i] = padding[i];
		i++;
	}
	while (src && i < width)
	{
		res[i] = *src;
		i++;
		src++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_str_padding(int width, char *src, char *padding, int start)
{
	char	*dest;
	int		i;
	int		final_width;

	final_width = ft_max_width(width, src);
	i = 0;
	dest = (char *)malloc(sizeof(char) *(final_width + 1));
	if (!dest)
		return (NULL);
	while (*src && i != start)
	{
		dest[i++] = *src;
		src++;
	}
	while (padding && i != (final_width - ft_pf_strlen(src)))
		dest[i++] = *padding;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_char_padding(t_print *tab, char *src, char *padding)
{
	char	*dest;
	int		i;
	int		width;

	width = ft_max_width(tab->width, src);
	i = 1;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if (!dest)
		return (NULL);
	dest[0] = *src;
	while (padding && i != width + 1)
	{
		dest[i] = *padding;
		i++;
	}
	return (dest);
}

char	*ft_int_add_char(long long int d, char c)
{
	int		i;
	char	*dest;
	char	*src;
	int		j;

	i = 1;
	j = 0;
	if (!c || d < 0)
		return (ft_pf_itoa(d));
	else
	{
		src = ft_pf_itoa(d);
		dest = (char *)malloc(sizeof(char) * (ft_pf_strlen(src) + 2));
		dest[0] = c;
		while (src[j])
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
	}
	free(src);
	return (dest);
}
