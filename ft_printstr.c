/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:52:14 by aabuward          #+#    #+#             */
/*   Updated: 2026/10/05 13:55:29 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int		st;

	if (!str)
	{
		st = ft_putstr_fd("(null)", 1);
		return (st);
	}
	st = ft_putstr_fd(str, 1);
	return (st);
}
