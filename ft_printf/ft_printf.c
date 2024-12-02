/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:12:47 by kadachi           #+#    #+#             */
/*   Updated: 2024/12/01 20:17:45 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_format(const char *format, va_list argp)
{
	if (format[1] == 'c')
		return (print_char(va_arg(argp, int)));
	if (format[1] == 's')
		return (print_str(va_arg(argp, char *)));
	if (format[1] == 'p')
		return (print_ptr(va_arg(argp, unsigned long)));
	if (format[1] == 'd' || format[1] == 'i')
		return (print_int(va_arg(argp, int), 0, "0123456789"));
	if (format[1] == 'u')
		return (print_int(va_arg(argp, unsigned int), 1, "0123456789"));
	if (format[1] == 'x')
		return (print_int(va_arg(argp, unsigned int), 1, "0123456789abcdef"));
	if (format[1] == 'X')
		return (print_int(va_arg(argp, unsigned int), 1, "0123456789ABCDEF"));
	if (format[1] == '%')
		return (print_char('%'));
	return (-1);
}

int	ft_vprintf(const char *format, va_list argp)
{
	int	size;
	int	tmp;

	size = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			tmp = select_format(format, argp);
			if (tmp == -1)
				return (-1);
			format += 2;
		}
		else
		{
			tmp = print_raw(format);
			if (tmp == -1)
				return (-1);
			format += tmp;
		}
		size += tmp;
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		size;

	if (format == NULL)
		return (-1);
	va_start(argp, format);
	size = ft_vprintf(format, argp);
	va_end(argp);
	return (size);
}
