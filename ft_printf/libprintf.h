/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:36:50 by eleotard          #+#    #+#             */
/*   Updated: 2022/01/06 14:42:44 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putstr(char *s, int *length);
void	ft_putchar(char c, int *length);
void	ft_putnbr(int n, int *length);
void	ft_puthexa(unsigned int n, int *length);
void	ft_upperhexa(unsigned int n, int *length);
void	ft_putui(unsigned int n, int *length);
void	ft_putaddr(unsigned long long n, int *length);

#endif
