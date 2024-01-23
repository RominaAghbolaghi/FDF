/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:10:24 by shabibol          #+#    #+#             */
/*   Updated: 2023/05/05 12:19:46 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*place;

	if (!*lst)
		return ;
	while (*lst)
	{
		place = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = place;
	}
}
