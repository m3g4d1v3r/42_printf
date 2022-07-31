/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:27:53 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:05:13 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static unsigned int	ft_base_uint_nbr(unsigned int n)
{
	unsigned int	base;

	base = 1;
	while (n >= 10)
	{
		n /= 10;
		base *= 10;
	}
	return (base);
}

int	ft_putuint_fd(unsigned int n, int fd)
{
	unsigned int	nbr_base;
	unsigned int	chrs_written;
	char			chr_to_write;

	chrs_written = 0;
	nbr_base = ft_base_uint_nbr(n);
	while (nbr_base)
	{
		chr_to_write = (n / nbr_base) % 10 + '0';
		write(fd, &chr_to_write, 1);
		chrs_written++;
		nbr_base /= 10;
	}
	return (chrs_written);
}
