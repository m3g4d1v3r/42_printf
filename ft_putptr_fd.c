/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:13:30 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 12:18:44 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_base_hexptr_nbr(unsigned long long n)
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

static int	ft_puthexptr_fd(unsigned long long n, const char *hex_base, int fd)
{
	unsigned long long	nbr_base;
	unsigned long long	chrs_written;

	chrs_written = 0;
	nbr_base = ft_base_hexptr_nbr(n);
	while (nbr_base)
	{
		write(fd, &hex_base[(n / nbr_base) % 0x10], 1);
		chrs_written++;
		nbr_base /= 0x10;
	}
	return (chrs_written);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	static const char	*hex_base = "0123456789abcdef";
	if (ptr == NULL)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write(fd, "0x", 2);
	return (ft_puthexptr_fd((unsigned long long) ptr, hex_base, fd) + 2);
}
