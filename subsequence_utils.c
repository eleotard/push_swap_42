/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 03:11:11 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/09 03:11:45 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_tab(int *tab, int size)
{
	int	i;
	int	min;

	i = -1;
	min = tab[0];
	while (++i < size)
	{
		if (tab[i] < min)
			min = tab[i];
	}
	return (min);
}

int	ft_find_max_tab(int *tab, int size)
{
	int	i;
	int	max;

	i = -1;
	max = tab[0];
	while (++i < size)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return (max);
}
