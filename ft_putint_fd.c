/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:54:45 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/27 20:49:42 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_ten_nbr(long n)
{
	int	base;

	base = 1;
	while (n >= 10)
	{
		n /= 10;
		base *= 10;
	}
	return (base);
}

int	ft_putint_fd(int n, int fd)
{
	long	aux_nb;
	int		nbr_base;
	char	chr_to_write;
	int		chrs_written;

	aux_nb = (long) n;
	chrs_written = 0;
	if (n < 0)
	{
		aux_nb *= -1;
		write(fd, "-", 1);
		chrs_written++;
	}
	nbr_base = ft_base_ten_nbr(aux_nb);
	while (nbr_base)
	{
		chr_to_write = (aux_nb / nbr_base) % 10 + '0';
		write(fd, &chr_to_write, 1);
		chrs_written++;
		nbr_base /= 10;
	}
	return (chrs_written);
}
