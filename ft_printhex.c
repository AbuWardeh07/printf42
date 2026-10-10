/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:52:43 by aabuward          #+#    #+#             */
/*   Updated: 2026/10/05 14:48:06 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printhex(unsigned long num, char format)
{
	char	*base;
	int		len;
	int		st;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = 0;
	if (num >= 16)
	{
		st = ft_printhex(num / 16, format);
		if (st == -1)
			return (st);
		len += st;
	}
	st = ft_printchar(base[num % 16]);
	if (st == -1)
		return (st);
	len += st;
	return (len);
}
