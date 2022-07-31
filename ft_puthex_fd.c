/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:54:45 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/27 21:58:54 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static unsigned long long	ft_base_hex_nbr(unsigned long long n)
{
	unsigned long long	base;

	base = 1;
	while (n >= 0x10)
	{
		n /= 0x10;
		base *= 0x10;
	}
	return (base);
}

static int	ft_puthex_fd(unsigned long long n, const char *hex_base, int fd)
{
	unsigned long long	nbr_base;
	unsigned long long	chrs_written;

	chrs_written = 0;
	nbr_base = ft_base_hex_nbr(n);
	while (nbr_base)
	{
		write(fd, &hex_base[(n / nbr_base) % 0x10], 1);
		chrs_written++;
		nbr_base /= 0x10;
	}
	return (chrs_written);
}

int	ft_puthex_upper_fd(unsigned long long n, int fd)
{
	static const char	*hex_uppercase_base = "0123456789ABCDEF";

	return (ft_puthex_fd(n, hex_uppercase_base, fd));
}

int	ft_puthex_down_fd(unsigned long long n, int fd)
{
	static const char	*hex_downcase_base = "0123456789abcdef";

	return (ft_puthex_fd(n, hex_downcase_base, fd));
}

int	ft_putptr_fd(void *ptr, int fd)
{
	if (ptr == NULL)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write(fd, "0x", 2);
	return (ft_puthex_down_fd((unsigned long long) ptr, fd) + 2);
}
