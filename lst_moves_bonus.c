/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:42:20 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/24 17:52:28 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_lst(t_lst *begin, char *s_name)
{
	int	tmp_a;

	if (ft_lstsize_p(&begin) <= 1)
		return ;
	tmp_a = begin->content;
	begin->content = begin->next->content;
	begin->next->content = tmp_a;
	if (!s_name)
		return ;
}

void	ft_rotate_up(t_lst **alst, char *s_name)
{
	t_lst	*buff;
	t_lst	*begin;

	if (ft_lstsize_p(alst) <= 1)
		return ;
	begin = *alst;
	*alst = (*alst)->next;
	buff = *alst;
	while (buff->next)
		buff = buff->next;
	buff->next = begin;
	begin->next = NULL;
	if (!s_name)
		return ;
}

void	ft_rotate_down(t_lst **alst, char *s_name)
{
	t_lst	*buff;
	t_lst	*begin;
	t_lst	*other;
	int		lst_size;
	int		i;

	if (ft_lstsize_p(alst) <= 1)
		return ;
	lst_size = ft_lstsize_p(alst);
	begin = *alst;
	buff = *alst;
	while (buff->next)
		buff = buff->next;
	*alst = buff;
	(*alst)->next = begin;
	i = 0;
	other = *alst;
	while (i != lst_size - 1)
	{
		other = other->next;
		i++;
	}
	other->next = NULL;
	if (!s_name)
		return ;
}

void	ft_push_b(t_lst **s_a, t_lst **s_b)
{
	t_lst	*begin_s_a;

	if (*s_a == NULL)
		return ;
	begin_s_a = *s_a;
	*s_a = (*s_a)->next;
	begin_s_a->next = *s_b;
	*s_b = begin_s_a;
}

void	ft_push_a(t_lst **s_a, t_lst **s_b)
{
	t_lst	*begin_s_b;

	if (*s_b == NULL)
		return ;
	begin_s_b = *s_b;
	*s_b = (*s_b)->next;
	begin_s_b->next = *s_a;
	*s_a = begin_s_b;
}
