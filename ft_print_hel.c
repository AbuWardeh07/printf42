/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 11:45:19 by aabuward          #+#    #+#             */
/*   Updated: 2026/09/30 14:58:15 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_fd(long n)
{
	char	cc;
	int		st;
	int		tot;

	tot = 0;
	if (n < 0)
	{
		st = write(1, "-", 1);
		if (st == -1)
			return (-1);
		tot += st;
		n *= -1;
	}
	if (n >= 10)
	{
		st = ft_putnbr_fd(n / 10);
		if (st == -1)
			return (-1);
		tot += st;
	}
	cc = (n % 10) + '0';
	st = ft_printchar(cc);
	if (st == -1)
		return (-1);
	return (tot + st);
}

int	ft_putstr_fd(char *s, int fd)
{
	int		i;
	int		st;
	int		tot;

	i = 0;
	tot = 0;
	while (s[i])
	{
		st = write(fd, &s[i], 1);
		if (st == -1)
			return (st);
		tot += st;
		i++;
	}
	return (tot);
}
