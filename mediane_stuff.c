/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:08 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/09 00:50:35 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_cpy_list_in_tab(t_lst **s_a, int size)
{
	int		i;
	t_lst	*buff;
	int		*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	buff = *s_a;
	i = -1;
	while (buff)
	{
		tab[++i] = buff->content;
		buff = buff->next;
	}
	return (tab);
}

void	ft_sort_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
			ft_swap(&tab[i], &tab[i + 1]);
		i++;
	}
}

int	*ft_create_sorted_tab(t_lst **s_a, t_lst **s_b, int size)
{
	int		i;
	int		*tab;

	tab = ft_cpy_list_in_tab(s_a, size);
	if (!tab)
		ft_free_lst_exit(s_a, s_b);
	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_sort_tab(tab, size);
			i = -1;
		}
	}
	return (tab);
}

int	ft_find_mediane(t_lst **s_a, t_lst **s_b)
{
	int		mediane;
	int		lst_size;
	int		*tab;

	lst_size = ft_lstsize_p(s_a);
	tab = ft_create_sorted_tab(s_a, s_b, lst_size);
	mediane = tab[(lst_size - 1) / 2];
	free(tab);
	return (mediane);
}
