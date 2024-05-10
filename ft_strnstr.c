/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:29:40 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:05:45 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	i;

	h = (char *)haystack;
	n = (char *)needle;
	i = 0;
	if (needle == haystack)
		return (h);
	if (!haystack && len == 0)
		return (NULL);
	if (!needle && ft_strlen(needle) == 0)
		return (h);
	while (h[i] && i <= len && (ft_strlen(n) <= (len - i)))
	{
		if (ft_strncmp(h + i, n, ft_strlen(n)) == 0)
			return (h + i);
		else
			i++;
	}
	return (0);
}
