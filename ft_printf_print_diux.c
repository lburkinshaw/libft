/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_diux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:38:50 by lburkins          #+#    #+#             */
/*   Updated: 2024/01/31 14:55:54 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printnbr_diu(long n, int *check)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += printstr("-2147483648", check);
	else if (n < 0)
	{
		count += printchar('-', check);
		count += printnbr_diu(-n, check);
	}
	else if (n > 9)
	{
		count += printnbr_diu((n / 10), check);
		count += printchar((n % 10 + '0'), check);
	}
	else
		count += printchar((n + '0'), check);
	return (count);
}

int	printnbr_hex(unsigned int n, const char upper_lower, int *check)
{
	int		count;
	char	*symbols;

	if (upper_lower == 'x')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
	{
		count += printnbr_hex((n / 16), upper_lower, check);
		count += printchar(symbols[n % 16], check);
	}
	else
		count += printchar(symbols[n], check);
	return (count);
}
