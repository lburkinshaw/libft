/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:51:48 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:04:35 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;
	size_t			i;

	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	i = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	return (dst);
}
