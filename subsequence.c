/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:28:59 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/29 17:53:40 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_calloc_tabs(int size, int nb)
{
	int	*tab;
	int	k;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	k = -1;
	while (++k < size)
		tab[k] = nb;
	return (tab);
}

void	ft_init_struct_tab(t_tab *va, t_lst **s_a, int size)
{
	va->tab = ft_cpy_list_in_tab(s_a, size);
	if (!va->tab)
		ft_free_tabs_lst_exit(s_a, NULL, NULL, NULL);
	va->tab_cpy = ft_calloc_tabs(size, 1);
	if (!va->tab_cpy)
		ft_free_tabs_lst_exit(s_a, va->tab, NULL, NULL);
	va->tab_index = ft_calloc_tabs(size, 0);
	if (!va->tab_index)
		ft_free_tabs_lst_exit(s_a, va->tab, va->tab_cpy, NULL);
}

void	ft_put_min_on_top(t_lst **s_a)
{
	int		min;
	int		i;
	int		size;
	t_lst	*buff;

	buff = *s_a;
	size = ft_lstsize_p(s_a);
	min = ft_find_min_lst(s_a);
	i = 0;
	while (buff->content != min)
	{
		buff = buff->next;
		i++;
	}
	if (i < size / 2)
	{
		while ((*s_a)->content != min)
			ft_rotate_up(s_a, "a");
	}
	else
	{
		while ((*s_a)->content != min)
			ft_rotate_down(s_a, "a");
	}
}

void	ft_find_subsequence(t_lst **s_a, t_tab *va, int size)
{
	int		i;
	int		j;

	ft_put_min_on_top(s_a);
	ft_init_struct_tab(va, s_a, size);
	i = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (va->tab[j] < va->tab[i])
			{
				if (va->tab_cpy[j] + 1 >= va->tab_cpy[i])
				{
					va->tab_cpy[i] = va->tab_cpy[j] + 1;
					va->tab_index[i] = j;
				}
			}
		}
	}
	ft_create_tab_sequence(s_a, va, size);
	ft_free_tabs(va->tab, va->tab_cpy, va->tab_index);
}

void	ft_create_tab_sequence(t_lst **s_a, t_tab *va, int size)
{
	int	i;
	int	j;
	int	max;

	va->size_sequence = ft_find_max_tab(va->tab_cpy, size);
	va->tab_sequence = malloc(sizeof(int) * va->size_sequence);
	if (!va->tab_sequence)
		ft_free_tabs_lst_exit(s_a, va->tab, va->tab_cpy, va->tab_index);
	i = -1;
	max = va->tab_cpy[0];
	while (++i < size)
	{
		if (va->tab_cpy[i] > max)
		{
			max = va->tab_cpy[i];
			j = i;
		}
	}
	i = va->size_sequence - 1;
	va->tab_sequence[i] = va->tab[j];
	while (--i >= 0)
	{
		va->tab_sequence[i] = va->tab[va->tab_index[j]];
		j = va->tab_index[j];
	}
}
