/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:51:26 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 12:59:37 by msubtil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_state
{
	OFF,
	ON,
	DONE
}	t_state;

int		ft_printf(const char *format, ...);

// parser functions:
void	ft_parse_chr(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c);
void	ft_parse_hex(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c);
void	ft_parse_int(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c);
void	ft_parse_ptr(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c);
void	ft_parse_str(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c);
void	ft_parse_uint(va_list *args_ptr, t_state *fmt_st, char chr, int *chr_c);

// putnbr functions:
int		ft_puthex_upper_fd(unsigned int n, int fd);
int		ft_puthex_lower_fd(unsigned int n, int fd);
int		ft_putint_fd(int n, int fd);
int		ft_putptr_fd(void *ptr, int fd);
int		ft_putuint_fd(unsigned int n, int fd);

#endif
