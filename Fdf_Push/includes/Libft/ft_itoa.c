/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:09:26 by shabibol          #+#    #+#             */
/*   Updated: 2023/04/28 11:51:00 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_digits(int n)
{
	size_t	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*result;
	long int	num;
	size_t		digit;

	num = n;
	digit = ft_get_digits(n);
	if (n <= 0)
	{
		num *= -1;
		digit++;
	}
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	result[digit] = '\0';
	while (digit--)
	{
		result[digit] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
