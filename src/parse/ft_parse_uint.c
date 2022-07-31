/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:03:58 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:04:12 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parse_uint(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c)
{
	unsigned int	the_uint;

	if (*fmt_st == DONE)
		return ;
	if (chr == 'u')
	{
		the_uint = va_arg(*args_ptr, unsigned int);
		(*chr_c) += ft_putuint_fd(the_uint, 1);
		*fmt_st = DONE;
	}
}
