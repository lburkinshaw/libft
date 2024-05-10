/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:50:49 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:05:58 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		else
			i--;
	}
	if (ch == s[0])
		return ((char *)&s[i]);
	else
		return (0);
}
