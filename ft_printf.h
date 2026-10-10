/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabuward <aabuward@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:53:09 by aabuward          #+#    #+#             */
/*   Updated: 2026/10/03 11:05:23 by aabuward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnbr(long n);
int		ft_printunsigned(unsigned int n);
int		ft_printhex(unsigned long num, char format);
int		ft_printptr(void *ptr);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long n);
#endif
