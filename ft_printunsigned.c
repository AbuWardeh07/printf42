/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:51:34 by aabuward          #+#    #+#             */
/*   Updated: 2026/09/30 12:20:30 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int		tot;
	int		len;
	char	p;

	tot = 0;
	if (n >= 10)
	{
		len = ft_printunsigned(n / 10);
		if (len == -1)
			return (-1);
		tot += len;
	}
	p = n % 10 + '0';
	len = ft_printchar(p);
	if (len == -1)
		return (-1);
	tot += len;
	return (tot);
}
