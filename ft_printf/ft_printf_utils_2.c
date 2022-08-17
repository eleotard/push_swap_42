/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:43:19 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/17 19:44:52 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_upperhexa(unsigned int n, int *length)
{
	char	*basehexa;

	basehexa = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_upperhexa(n / 16, length);
		ft_putchar(basehexa[n % 16], length);
	}
	else
		ft_putchar(basehexa[n], length);
}

void	ft_puthexx(unsigned long long n, int *length)
{
	char	*basehexa;

	basehexa = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthexx((n / 16), length);
		ft_putchar(basehexa[n % 16], length);
	}
	else
		ft_putchar(basehexa[n], length);
}

void	ft_putaddr(unsigned long long n, int *length)
{
	ft_putstr("0x", length);
	ft_puthexx(n, length);
}
