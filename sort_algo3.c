/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:55:39 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/11 21:02:43 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_content_in_sequence(int content, t_tab *va)
{
	int	i;

	i = -1;
	while (++i < va->size_sequence)
	{
		if (content == va->tab_sequence[i])
			return (1);
	}
	return (0);
}

int	ft_find_index_min(int *tab, int size)
{
	int	i;
	int	min;

	i = 0;
	min = ft_find_min_tab(tab, size);
	while (tab[i] != min)
		i++;
	return (i);
}
