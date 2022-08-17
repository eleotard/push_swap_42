/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:55:39 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/24 17:41:36 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	**ft_sort_algo(t_lst **s_a, t_lst **s_b, int mediane)
{
	int		j;
	int		pos_s_b;

	j = 0;
	pos_s_b = 0;
	ft_push_all_b_except_sequence(s_a, s_b, mediane);
	ft_target_nb_to_move(s_a, s_b, pos_s_b, j);
	ft_rotate_when_done(s_a, ft_find_min_lst(s_a));
	return (s_a);
}

void	ft_push_all_b_except_sequence(t_lst **s_a, t_lst **s_b, int mediane)
{
	t_tab	va;
	int		size_sa;
	int		i;

	i = -1;
	size_sa = ft_lstsize_p(s_a);
	ft_find_subsequence(s_a, &va, size_sa);
	while (++i < size_sa)
	{
		if (ft_find_content_in_sequence((*s_a)->content, &va) == 0)
		{
			if ((*s_a)->content > mediane)
			{
				ft_push_b(s_a, s_b);
				if (ft_lstsize_p(s_b) > 1)
					ft_rotate_up(s_b, "b");
			}
			else
				ft_push_b(s_a, s_b);
		}
		else if (ft_find_content_in_sequence((*s_a)->content, &va) == 1)
			ft_rotate_up(s_a, "a");
	}
	free(va.tab_sequence);
}

void	ft_target_nb_to_move(t_lst **s_a, t_lst **s_b, int pos_s_b, int j)
{
	t_lst	*buff;
	int		*tab_moves;
	int		strict_sup;
	int		pos_s_a;

	while (*s_b != NULL)
	{
		buff = *s_b;
		pos_s_b = -1;
		tab_moves = ft_create_tab_moves(s_a, s_b);
		j = ft_find_index_min(tab_moves, ft_lstsize_p(s_b));
		while (++pos_s_b < j)
			buff = buff->next;
		pos_s_b++;
		if (pos_s_b > ft_lstsize_p(s_b) / 2)
			pos_s_b = pos_s_b - (ft_lstsize_p(s_b) + 1);
		strict_sup = ft_find_strict_superior(s_a, buff->content);
		pos_s_a = ft_find_pos_nbr(s_a, strict_sup);
		ft_do_moves(s_a, s_b, pos_s_a, pos_s_b);
		free(tab_moves);
		tab_moves = NULL;
	}
}

int	*ft_create_tab_moves(t_lst **s_a, t_lst **s_b)
{
	int			*tab_moves;
	int			pos[2];
	t_lst		*buff_b;
	long int	strict_sup;
	int			i;

	tab_moves = malloc(sizeof(int) * ft_lstsize_p(s_b));
	if (!tab_moves)
		ft_free_lst_exit(s_a, s_b);
	buff_b = *s_b;
	i = 0;
	while (buff_b)
	{
		pos[1] = ft_find_pos_nbr(s_b, buff_b->content);
		strict_sup = ft_find_strict_superior(s_a, buff_b->content);
		pos[0] = ft_find_pos_nbr(s_a, strict_sup);
		tab_moves[i] = ft_count(pos[0], pos[1]);
		i++;
		buff_b = buff_b->next;
	}
	return (tab_moves);
}

int	ft_find_pos_nbr(t_lst **stack, int nbr)
{
	int		i;
	t_lst	*buff_tmp;
	int		size;

	size = ft_lstsize_p(stack);
	i = 1;
	buff_tmp = *stack;
	while (buff_tmp->content != nbr)
	{
		i++;
		buff_tmp = buff_tmp->next;
	}
	if (i > size / 2)
		i = i - (size + 1);
	return (i);
}
