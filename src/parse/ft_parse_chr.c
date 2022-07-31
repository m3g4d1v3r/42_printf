/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:00:46 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:01:31 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parse_chr(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c)
{
	char	the_chr;

	if (*fmt_st == DONE)
		return ;
	if (chr == '%')
	{
		write(1, "%", 1);
		(*chr_c)++;
		*fmt_st = DONE;
	}
	else if (chr == 'c')
	{
		the_chr = (char) va_arg(*args_ptr, int);
		write(1, &the_chr, 1);
		(*chr_c)++;
		*fmt_st = DONE;
	}
}
