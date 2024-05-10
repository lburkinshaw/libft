/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:01:35 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/08 11:23:58 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	count = 0;
	ptr = lst;
	if (lst == '\0')
		return (0);
	while (ptr != '\0')
	{
		ptr = ptr -> next;
		count++;
	}
	return (count);
}
