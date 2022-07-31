/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:08:37 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 12:00:56 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_percent(t_state *format_flag, char chr, int *chrs_written)
{
	if (*format_flag == DONE)
		return ;
	if (chr == '%')
	{
		write(1, "%", 1);
		(*chrs_written)++;
		*format_flag = OFF;
	}
}

void	process_char(va_list *args_ptr, t_state *format_flag, char chr, int *chrs_written)
{
	char	the_chr;

	if (*format_flag == DONE)
		return ;
	if (chr == 'c')
	{
		the_chr = (char) va_arg(*args_ptr, int);
		write(1, &the_chr, 1);
		(*chrs_written)++;
		*format_flag = DONE;
	}
}

void	process_string(va_list *args_ptr, t_state *format_flag, char chr, int *chrs_written)
{
	char	*the_str;

	if (*format_flag == DONE)
		return ;
	if (chr == 's')
	{
		the_str = (char *) va_arg(*args_ptr, int *);
		if (the_str == NULL)
		{
			write(1, "(null)", 6);
			(*chrs_written) += 6;
		}
		else
		{
			while (*the_str != '\0')
			{
				write(1, the_str++, 1);
				(*chrs_written)++;
			}
		}
		*format_flag = DONE;
	}
}

void	process_pointer(va_list *args_ptr, t_state *format_flag, char chr, int *chrs_written)
{
	void	*the_ptr;

	if (*format_flag == DONE)
		return ;
	if (chr == 'p')
	{
		the_ptr = va_arg(*args_ptr, void *);
		(*chrs_written) += ft_putptr_fd(the_ptr, 1);
		*format_flag = DONE;
	}
}

void	process_hex(va_list *args_ptr, t_state *format_flag, char chr, int *chrs_written)
{
	unsigned int	the_hex;

	if (*format_flag == DONE)
		return ;
	if (chr == 'x' || chr == 'X')
	{
		the_hex = va_arg(*args_ptr, unsigned int);
		if (chr == 'x')
			(*chrs_written) += ft_puthex_down_fd(the_hex, 1);
		else
			(*chrs_written) += ft_puthex_upper_fd(the_hex, 1);
		*format_flag = DONE;
	}
}

void	process_int(va_list *args_ptr, t_state *format_flag, char chr, int *chrs_written)
{
	int	the_integer;

	if (*format_flag == DONE)
		return ;
	if (chr == 'd')
	{
		the_integer = va_arg(*args_ptr, int);
		(*chrs_written) += ft_putint_fd(the_integer, 1);
		*format_flag = DONE;
	}
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	t_state	format_flag;
	int		chrs_written;

	format_flag = OFF;
	va_start(args, format_str);
	chrs_written = 0;
	while (*format_str != '\0')
	{
		if (format_flag == OFF)
		{
			if (*format_str == '%')
				format_flag = ON;
			else
			{
				write(1, format_str, 1);
				chrs_written++;
			}
		}
		else
		{
			process_percent(&format_flag, *format_str, &chrs_written);
			process_char(&args, &format_flag, *format_str, &chrs_written);
			process_string(&args, &format_flag, *format_str, &chrs_written);
			process_int(&args, &format_flag, *format_str, &chrs_written);
			process_pointer(&args, &format_flag, *format_str, &chrs_written);
			process_hex(&args, &format_flag, *format_str, &chrs_written);
			if (format_flag == DONE)
				format_flag = OFF;
		}
		format_str++;
	}
	va_end(args);
	return (chrs_written);
}
