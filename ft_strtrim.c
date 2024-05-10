/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:19:09 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:06:05 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	size_t		trim_len;
	char		*trim;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start) != NULL)
		start++;
	while (end > start && ft_strchr(set, *end) != NULL)
		end--;
	trim_len = end - start + 1;
	trim = (char *)malloc((trim_len + 1) * sizeof(char));
	if (trim == 0)
		return (NULL);
	ft_strlcpy(trim, start, trim_len + 1);
	return (trim);
}
