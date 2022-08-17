/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:33:03 by wting             #+#    #+#             */
/*   Updated: 2022/08/14 19:00:16 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		*count += write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n *= -1;
	}
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
	return (0);
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (*s)
		*count += write(1, &*s++, 1);
}
