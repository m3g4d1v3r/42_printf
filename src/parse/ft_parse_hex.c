/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:02:59 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:03:16 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parse_hex(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c)
{
	unsigned int	the_hex;

	if (*fmt_st == DONE)
		return ;
	if (chr == 'x' || chr == 'X')
	{
		the_hex = va_arg(*args_ptr, unsigned int);
		if (chr == 'x')
			(*chr_c) += ft_puthex_lower_fd(the_hex, 1);
		else
			(*chr_c) += ft_puthex_upper_fd(the_hex, 1);
		*fmt_st = DONE;
	}
}
