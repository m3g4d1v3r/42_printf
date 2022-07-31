/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:08:37 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 13:05:37 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		{
			if (*format_str == '%')
				fmt_st = ON;
			else
			{
				write(1, format_str, 1);
				chr_counter++;
			}
		}
		else
		{
			ft_parse_chr(&args, &fmt_st, *format_str, &chr_counter);
			ft_parse_str(&args, &fmt_st, *format_str, &chr_counter);
			ft_parse_int(&args, &fmt_st, *format_str, &chr_counter);
			ft_parse_uint(&args, &fmt_st, *format_str, &chr_counter);
			ft_parse_ptr(&args, &fmt_st, *format_str, &chr_counter);
			ft_parse_hex(&args, &fmt_st, *format_str, &chr_counter);
			if (fmt_st == DONE)
				fmt_st = OFF;
		}
		format_str++;
	}
	va_end(args);
	return (chr_counter);
}
