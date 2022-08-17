/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:55:39 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/23 22:54:34 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_moves(t_lst **s_a, t_lst **s_b, int pos_s_a, int pos_s_b)
{
	if ((pos_s_a < 0 && pos_s_b > 0) || (pos_s_a > 0 && pos_s_b < 0))
		ft_sort_pos_up_down(s_a, s_b, pos_s_a, pos_s_b);
	else if ((pos_s_a > 0 && pos_s_b > 0))
		ft_sort_pos_up_up(s_a, s_b, pos_s_a, pos_s_b);
	else if (pos_s_a < 0 && pos_s_b < 0)
		ft_sort_pos_down_down(s_a, s_b, pos_s_a, pos_s_b);
}

void	ft_sort_pos_up_down(t_lst **s_a, t_lst **s_b, int pos_s_a, int pos_s_b)
{
	int	i;

	i = -1;
	if (pos_s_a < 0 && pos_s_b > 0)
	{
		while (++i < pos_s_a *(-1))
			ft_rotate_down(s_a, "a");
		i = -1;
		while (++i < pos_s_b - 1)
			ft_rotate_up(s_b, "b");
		ft_push_a(s_a, s_b);
	}
	else if (pos_s_a > 0 && pos_s_b < 0)
	{
		while (++i < pos_s_a - 1)
			ft_rotate_up(s_a, "a");
		i = -1;
		while (++i < pos_s_b * (-1))
			ft_rotate_down(s_b, "b");
		ft_push_a(s_a, s_b);
	}
}

void	ft_sort_pos_up_up(t_lst **s_a, t_lst **s_b, int pos_s_a, int pos_s_b)
{
	int	i;

	i = -1;
	if (pos_s_a >= pos_s_b)
	{
		while (++i < pos_s_b - 1)
			ft_rotate_up_all(s_a, s_b);
		i = -1;
		while (++i < pos_s_a - pos_s_b)
			ft_rotate_up(s_a, "a");
		ft_push_a(s_a, s_b);
	}
	else if (pos_s_b > pos_s_a)
	{
		while (++i < pos_s_a - 1)
			ft_rotate_up_all(s_a, s_b);
		i = -1;
		while (++i < pos_s_b - pos_s_a)
			ft_rotate_up(s_b, "b");
		ft_push_a(s_a, s_b);
	}
}

void	ft_sort_pos_down_down(t_lst **s_a, t_lst **s_b, int pos_s_a,
	int pos_s_b)
{
	int	i;

	i = -1;
	if (pos_s_a >= pos_s_b)
	{
		while (++i < (pos_s_a *(-1)))
			ft_rotate_down_all(s_a, s_b);
		i = -1;
		while (++i < (pos_s_b - pos_s_a) * -1)
			ft_rotate_down(s_b, "b");
		ft_push_a(s_a, s_b);
	}
	else if (pos_s_b > pos_s_a)
	{
		while (++i < (pos_s_b *(-1)))
			ft_rotate_down_all(s_a, s_b);
		i = -1;
		while (++i < (pos_s_a - pos_s_b) * -1)
			ft_rotate_down(s_a, "a");
		ft_push_a(s_a, s_b);
	}
}

int	ft_count(int pos_s_a, int pos_s_b)
{
	int		count;

	count = 0;
	if (pos_s_a < 0 && pos_s_b > 0)
		count = pos_s_a *(-1) + (pos_s_b - 1);
	else if (pos_s_a > 0 && pos_s_b < 0)
		count = (pos_s_a - 1) + pos_s_b *(-1);
	else if (pos_s_a > 0 && pos_s_b > 0)
	{
		if (pos_s_a >= pos_s_b)
			count = pos_s_a;
		else if (pos_s_b > pos_s_a)
			count = pos_s_b;
	}
	else if (pos_s_a < 0 && pos_s_b < 0)
	{
		if (pos_s_a <= pos_s_b)
			count = pos_s_a * (-1);
		else if (pos_s_b < pos_s_a)
			count = pos_s_b * (-1);
	}
	return (count);
}
