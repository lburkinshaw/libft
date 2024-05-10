/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:13:54 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:06:21 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	sublen;

	i = start;
	j = 0;
	if (s == NULL || start >= ft_strlen(s) || len == 0)
		return ((char *)ft_calloc(1, 1));
	sublen = ft_strlen(s + start);
	if (len > sublen)
		len = sublen;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] && j < len)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
