/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:29:22 by wting             #+#    #+#             */
/*   Updated: 2022/08/10 18:53:46 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
	{
		n += '0';
		*count += write(1, &n, 1);
	}
}

void	check_specs(va_list args, char spec, int *count)
{
	if (spec == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (spec == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (spec == 'i' || spec == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (spec == 'u')
		print_unsigned(va_arg(args, unsigned int), count);
	else if (spec == 'p')
		print_pointer(va_arg(args, unsigned long long), count);
	else if (spec == 'x')
		print_hex(va_arg(args, unsigned int), count);
	else if (spec == 'X')
		print_hex_u(va_arg(args, unsigned int), count);
	else if (spec == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = -1;
	count = 0;
	va_start(args, format);
	while (++i < (int)ft_strlen(format) && format[i])
	{
		if (format[i] == '%')
		{
			check_specs(args, format[++i], &count);
		}
		else
			count += ft_putchar(format[i]);
	}
	va_end(args);
	return (count);
}
