/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:02:33 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:02:48 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parse_ptr(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c)
{
	void	*the_ptr;

	if (*fmt_st == DONE)
		return ;
	if (chr == 'p')
	{
		the_ptr = va_arg(*args_ptr, void *);
		(*chr_c) += ft_putptr_fd(the_ptr, 1);
		*fmt_st = DONE;
	}
}
