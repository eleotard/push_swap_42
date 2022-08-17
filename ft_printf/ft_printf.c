/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:22:24 by eleotard          #+#    #+#             */
/*   Updated: 2022/02/09 19:18:10 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_display(char c, va_list ag, int *length)
{
	if (c == 'c')
		ft_putchar((char)va_arg(ag, int), length);
	else if (c == 's')
		ft_putstr((char *)va_arg(ag, int *), length);
	else if (c == 'x')
		ft_puthexa(va_arg(ag, unsigned int), length);
	else if (c == 'X')
		ft_upperhexa(va_arg(ag, unsigned int), length);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ag, int), length);
	else if (c == 'u')
		ft_putui(va_arg(ag, unsigned int), length);
	else if (c == 'p')
		ft_putaddr((unsigned long long)va_arg(ag, void *), length);
	else if (c == '%')
		ft_putchar('%', length);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ag;

	i = 0;
	count = 0;
	va_start(ag, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			ft_display(s[i], ag, &count);
		}
		else
			ft_putchar(s[i], &count);
		i++;
	}
	va_end(ag);
	return (count);
}
