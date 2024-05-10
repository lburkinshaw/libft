/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:12:12 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:02:50 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_howlong(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*rtnstr;
	int		i;

	len = ft_howlong(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	rtnstr = (char *)malloc((len + 1) * sizeof(char));
	if (rtnstr == 0)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		rtnstr[0] = '-';
	}
	i = len;
	while (n > 0)
	{
		rtnstr[len-- -1] = (n % 10) + '0';
		n = n / 10;
	}
	rtnstr[i] = '\0';
	return (rtnstr);
}
