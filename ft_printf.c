/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:13:48 by lburkins          #+#    #+#             */
/*   Updated: 2024/01/31 15:02:53 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		check;

	check = 0;
	va_start(args, format);
	count = iterate(format, args, &check);
	va_end(args);
	if (check == -1)
		return (-1);
	return (count);
}

int	iterate(const char *format, va_list	args, int	*check)
{
	int	temp_count;
	int	count;

	count = 0;
	while (*format)
	{
		temp_count = 0;
		if (*format != '%')
			temp_count = printchar(*format, check);
		else
			temp_count = execute_fmt(*++format, args, check);
		count += temp_count;
		format++;
	}
	return (count);
}

int	execute_fmt(const char specifier, va_list args, int *check)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = printchar(va_arg(args, int), check);
	else if (specifier == 's')
		count = printstr(va_arg(args, const char *), check);
	else if (specifier == 'p')
		count = printptr((unsigned long int)va_arg(args, void *), check);
	else if (specifier == 'd' || specifier == 'i')
		count = printnbr_diu(va_arg(args, int), check);
	else if (specifier == 'u')
		count = printnbr_diu(va_arg(args, unsigned), check);
	else if (specifier == 'x' || specifier == 'X')
		count = printnbr_hex(va_arg(args, unsigned int), specifier, check);
	else if (specifier == '%')
		count = printchar('%', check);
	else
		return (0);
	return (count);
}
