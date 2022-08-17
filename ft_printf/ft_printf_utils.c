/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:41:40 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/17 19:42:55 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_putchar(char c, int *length)
{
	write(1, &c, 1);
	*length += 1;
}

void	ft_putstr(char *s, int *length)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		*length += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], length);
		i++;
	}
}

void	ft_putui(unsigned int n, int *length)
{
	if (n > 9)
	{
		ft_putui((n / 10), length);
		ft_putchar((n % 10) + '0', length);
	}
	else
		ft_putchar(n + '0', length);
}

void	ft_putnbr(int n, int *val)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", val);
	}
	else if (n < 0)
	{
		ft_putchar('-', val);
		n = n *(-1);
		ft_putnbr(n, val);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), val);
		ft_putchar((n % 10) + '0', val);
	}
	else
	{
		ft_putchar(n + '0', val);
	}
}

void	ft_puthexa(unsigned int n, int *val)
{
	char	*basehexa;

	basehexa = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthexa(n / 16, val);
		ft_putchar(basehexa[n % 16], val);
	}
	else
		ft_putchar(basehexa[n], val);
}
