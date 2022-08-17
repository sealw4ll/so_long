/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:03:58 by wting             #+#    #+#             */
/*   Updated: 2022/08/10 18:53:52 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int n, int *count)
{
	char	*sample;

	sample = "0123456789abcdef";
	if (n >= 16)
	{
		print_hex(n / 16, count);
		print_hex(n % 16, count);
	}
	else
		*count += write(1, &sample[n], 1);
}

void	print_hex_u(unsigned int n, int *count)
{
	char	*sample;

	sample = "0123456789ABCDEF";
	if (n >= 16)
	{
		print_hex_u(n / 16, count);
		print_hex_u(n % 16, count);
	}
	else
		*count += write(1, &sample[n], 1);
}

void	pointer_hex(unsigned long long n, int *count)
{
	char	*sample;

	sample = "0123456789abcdef";
	if (n >= 16)
	{
		pointer_hex(n / 16, count);
		pointer_hex(n % 16, count);
	}
	else
		*count += write(1, &sample[n], 1);
}

void	print_pointer(unsigned long long n, int *count)
{
	*count += ft_putchar('0');
	*count += ft_putchar('x');
	pointer_hex(n, count);
}
