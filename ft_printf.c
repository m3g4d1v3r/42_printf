/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:08:37 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 16:32:53 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_offstate(t_state *fmt_st, char chr, int *chr_c)
{
	if (chr == '%')
		*fmt_st = ON;
	else
	{
		write(1, &chr, 1);
		(*chr_c)++;
	}
}

static void	ft_onstate(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c)
{
	ft_parse_chr(args_ptr, fmt_st, chr, chr_c);
	ft_parse_str(args_ptr, fmt_st, chr, chr_c);
	ft_parse_int(args_ptr, fmt_st, chr, chr_c);
	ft_parse_uint(args_ptr, fmt_st, chr, chr_c);
	ft_parse_ptr(args_ptr, fmt_st, chr, chr_c);
	ft_parse_hex(args_ptr, fmt_st, chr, chr_c);
	if (*fmt_st == DONE)
		*fmt_st = OFF;
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	t_state	fmt_st;
	int		chr_counter;

	fmt_st = OFF;
	va_start(args, format_str);
	chr_counter = 0;
	while (*format_str != '\0')
	{
		if (fmt_st == OFF)
			ft_offstate(&fmt_st, *format_str, &chr_counter);
		else
			ft_onstate(&args, &fmt_st, *format_str, &chr_counter);
		format_str++;
	}
	va_end(args);
	return (chr_counter);
}
