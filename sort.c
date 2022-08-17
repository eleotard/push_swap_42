/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:07:50 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/24 17:41:54 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	**ft_sort_two(t_lst **s_a)
{
	ft_swap_lst(*s_a, "a");
	return (s_a);
}

t_lst	**ft_sort_three(t_lst **s_a)
{
	int	first;
	int	second;
	int	third;

	first = (*s_a)->content;
	second = (*s_a)->next->content;
	third = (*s_a)->next->next->content;
	if (first > second && first > third && second < third)
		ft_rotate_up(s_a, "a");
	else if (first > second && first > third && second > third)
	{
		ft_rotate_up(s_a, "a");
		ft_swap_lst(*s_a, "a");
	}
	else if (second > first && second > third && third < first)
		ft_rotate_down(s_a, "a");
	else if (second > first && second > third && third > first)
	{
		ft_rotate_down(s_a, "a");
		ft_swap_lst(*s_a, "a");
	}
	else if (third > first && third > second && first > second)
		ft_swap_lst(*s_a, "a");
	return (s_a);
}

t_lst	**ft_sort_five(t_lst **s_a, t_lst **s_b)
{
	int	count_moves_b1;
	int	count_moves_b2;
	int	min;

	ft_push_b(s_a, s_b);
	ft_push_b(s_a, s_b);
	s_a = ft_sort_three(s_a);
	count_moves_b1 = ft_count_moves(s_a, (*s_b)->content);
	count_moves_b2 = (ft_count_moves(s_a, (*s_b)->next->content) + 1);
	if (count_moves_b2 < count_moves_b1)
		ft_swap_lst(*s_b, "b");
	while (*s_b != NULL)
	{
		ft_rotate_correctly(s_a, (*s_b)->content);
		ft_push_a(s_a, s_b);
	}
	min = ft_find_min_lst(s_a);
	ft_rotate_when_done(s_a, min);
	return (s_a);
}

void	ft_rotate_correctly(t_lst **s_a, int content)
{
	int	s_max;

	s_max = ft_find_strict_superior(s_a, content);
	if (ft_rotation_direction(s_a, content) == RA)
	{
		while ((*s_a)->content != s_max)
			ft_rotate_up(s_a, "a");
	}
	else
	{
		while ((*s_a)->content != s_max)
			ft_rotate_down(s_a, "a");
	}
}

void	ft_rotate_when_done(t_lst **s_a, int min)
{
	if (ft_rotation_direction(s_a, min) == RA)
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
