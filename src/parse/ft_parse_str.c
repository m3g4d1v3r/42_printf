/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:01:47 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:02:14 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parse_str(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c)
{
	char	*the_str;

	if (*fmt_st == DONE)
		return ;
	if (chr == 's')
	{
		the_str = (char *) va_arg(*args_ptr, int *);
		if (the_str == NULL)
		{
			write(1, "(null)", 6);
			(*chr_c) += 6;
		}
		else
		{
			while (*the_str != '\0')
			{
				write(1, the_str++, 1);
				(*chr_c)++;
			}
		}
		*fmt_st = DONE;
	}
}
