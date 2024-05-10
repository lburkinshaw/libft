/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_csp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:37:29 by lburkins          #+#    #+#             */
/*   Updated: 2024/01/31 14:55:58 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printchar(int c, int *check)
{
	if (*check == -1)
		return (0);
	if (write(1, &c, 1) == -1)
	{
		*check = -1;
		return (0);
	}
	return (1);
}

int	printstr(const char *str, int *check)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
	{
		count += printstr("(null)", check);
		return (count);
	}
	while (str[i] != '\0')
	{
		count += printchar(str[count], check);
		i++;
	}
	return (count);
}

int	printptr(unsigned long int ptr, int *check)
{
	int	count;

	count = 0;
	if (!ptr)
		count += printstr("0x0", check);
	else
	{
		count += printstr("0x", check);
		count += printnbr_ptr(ptr, check);
	}
	return (count);
}

int	printnbr_ptr(unsigned long int n, int *check)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n > 15)
	{
		count += printnbr_ptr((n / 16), check);
		count += printchar(symbols[n % 16], check);
	}
	else
		count += printchar(symbols[n], check);
	return (count);
}
