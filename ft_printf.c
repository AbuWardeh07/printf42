/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:59:25 by aabuward          #+#    #+#             */
/*   Updated: 2026/10/10 14:31:54 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_format(va_list ar, char c)
{
	if (c == 'c')
		return (ft_printchar(va_arg(ar, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(ar, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(ar, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(ar, int)));
	else if (c == 'u')
		return (ft_printunsigned(va_arg(ar, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(ar, unsigned int), c));
	else if (c == '%')
		return (ft_printchar('%'));
	return (-1);
}

static int	ft_handle(va_list args, const char *format, int *i)
{
	if (format[*i] == '%' && format[*i + 1])
	{
		(*i)++;
		return (ft_format(args, format[*i]));
	}
	else
		return (ft_printchar(format[*i]));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		ret;

	if (!format)
		return (-1);
	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		ret = ft_handle(args, format, &i);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		len += ret;
		i++;
	}
	va_end(args);
	return (len);
}
