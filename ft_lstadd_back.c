/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:38:50 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/08 11:23:23 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			ptr = ft_lstlast(*(lst));
			ptr -> next = new;
		}
	}
}
