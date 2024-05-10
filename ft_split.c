/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:36:31 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:05:04 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strings(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}

static size_t	ft_count_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_free(char **array, size_t i)
{
	if (array[i] == 0)
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_strings;
	char	**split_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	num_strings = ft_count_strings(s, c);
	split_str = (char **)malloc((num_strings + 1) * sizeof(char *));
	if (split_str == NULL)
		return (NULL);
	while (i < num_strings && s[j])
	{
		if (s[j] != c && s[j] != '\0')
		{
			split_str[i] = ft_substr(s, j, ft_count_len(s + j, c));
			if (ft_free(split_str, i) == 1)
				return (NULL);
			j += ft_count_len(s + j, c);
			i++;
		}
		j++;
	}
	split_str[num_strings] = NULL;
	return (split_str);
}
