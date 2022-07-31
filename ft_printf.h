/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msubtil- <msubtil-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:51:26 by msubtil-          #+#    #+#             */
/*   Updated: 2022/07/31 12:18:57 by msubtil-         ###   ########.fr       */
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

int	ft_printf(const char *format, ...);
int	ft_putint_fd(int n, int fd);
int	ft_putptr_fd(void *ptr, int fd);
int	ft_puthex_upper_fd(unsigned int n, int fd);
int	ft_puthex_down_fd(unsigned int n, int fd);

#endif
