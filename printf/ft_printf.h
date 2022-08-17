/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:41:22 by wting             #+#    #+#             */
/*   Updated: 2022/08/10 18:45:46 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n, int *count);
void	ft_putstr(char *s, int *count);
void	print_hex(unsigned int n, int *count);
void	print_hex_u(unsigned int n, int *count);
void	print_pointer(unsigned long long n, int *count);

#endif