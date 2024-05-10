/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:50:28 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:02:30 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*mem;

	total_size = count * size;
	if (total_size < count && total_size < size)
		return (NULL);
	mem = (void *)malloc(total_size);
	if (mem == 0)
		return (NULL);
	ft_bzero(mem, total_size);
	return (mem);
}
