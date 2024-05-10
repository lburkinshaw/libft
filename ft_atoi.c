/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:08:41 by lburkins          #+#    #+#             */
/*   Updated: 2023/11/23 10:02:25 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_ovrflo(int neg)
{
	if (neg == 1)
		return ((int) FT_LONG_MAX);
	return ((int)-FT_LONG_MAX - 1L);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		isneg;
	long	nb;
	long	pre;

	i = 0;
	nb = 0;
	isneg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		pre = nb;
		nb = (nb * 10) + (str[i] - '0');
		if (nb < 0 || pre > nb)
			return (ft_check_ovrflo(isneg));
		i++;
	}
	return (nb * isneg);
}
