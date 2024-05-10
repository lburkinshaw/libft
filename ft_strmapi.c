/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:30 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:05:38 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtnstr;
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	rtnstr = (char *)malloc((len + 1) * sizeof(char));
	if (rtnstr == 0)
		return (NULL);
	while (i < len)
	{
		rtnstr[i] = (*f)(i, s[i]);
		i++;
	}
	rtnstr[i] = '\0';
	return (rtnstr);
}
