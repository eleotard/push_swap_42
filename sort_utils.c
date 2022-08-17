/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:23:05 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:42 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_lst(t_lst **s_a)
{
	t_lst	*buff;
	int		min;

	buff = *s_a;
	min = buff->content;
	while (buff->next)
	{
		if (buff->next->content < buff->content && buff->next->content < min)
			min = buff->next->content;
		buff = buff->next;
	}
	return (min);
}

int	ft_count_moves(t_lst **s_a, int number_b)
{
	t_lst	*buff;
	int		count;
	int		strict_max;

	count = 1;
	strict_max = ft_find_strict_superior(s_a, number_b);
	buff = *s_a;
	while (buff->content != strict_max && buff)
	{
		buff = buff->next;
		count++;
	}
	if (ft_rotation_direction(s_a, number_b) == RA)
		return (count);
	else
		return ((ft_lstsize_p(s_a) - count) + 2);
	return (count);
}

int	ft_rotation_direction(t_lst **s_a, int number_b)
{
	int		i;
	int		strict_max;
	int		lst_size;
	int		middle;
	t_lst	*buff;

	i = 0;
	strict_max = ft_find_strict_superior(s_a, number_b);
	lst_size = ft_lstsize_p(s_a);
	middle = (lst_size / 2);
	buff = *s_a;
	while (buff->content != strict_max && buff)
	{
		buff = buff->next;
		i++;
	}
	if (i < middle)
		return (RA);
	else
		return (RRA);
}

int	ft_find_strict_superior(t_lst **s_a, int number_b)
{
	t_lst		*buff;
	long int	strict_max;
	int			min;

	buff = *s_a;
	min = ft_find_min_lst(s_a);
	strict_max = 2147483648;
	while (buff)
	{
		if (buff->content > number_b && buff->content < strict_max)
			strict_max = buff->content;
		buff = buff->next;
	}
	if (strict_max == 2147483648)
		strict_max = min;
	return ((int)strict_max);
}
