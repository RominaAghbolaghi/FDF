/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <rmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:09:48 by shabibol          #+#    #+#             */
/*   Updated: 2023/04/28 11:51:05 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*repl;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	repl = ft_lstlast(*lst);
	repl->next = new;
}
