/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:52:33 by aabuward          #+#    #+#             */
/*   Updated: 2026/10/03 11:35:47 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	unsigned long	point;
	int				len;
	int				st;

	if (!ptr)
	{
		st = write (1, "(nil)", 5);
		return (st);
	}
	point = (unsigned long)ptr;
	st = write (1, "0x", 2);
	if (st == -1)
		return (-1);
	len = ft_printhex (point, 'x');
	if (len == -1)
		return (-1);
	return (2 + len);
}
