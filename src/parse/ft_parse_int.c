/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:03:31 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:03:46 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parse_int(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c)
{
	int	the_integer;

	if (*fmt_st == DONE)
		return ;
	if (chr == 'd' || chr == 'i')
	{
		the_integer = va_arg(*args_ptr, int);
		(*chr_c) += ft_putint_fd(the_integer, 1);
		*fmt_st = DONE;
	}
}
