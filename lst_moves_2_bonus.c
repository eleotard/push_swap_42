/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_moves_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:15:11 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/24 17:52:31 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_all(t_lst **s_a, t_lst **s_b)
{
	ft_swap_lst(*s_a, NULL);
	ft_swap_lst(*s_b, NULL);
}

void	ft_rotate_up_all(t_lst **s_a, t_lst **s_b)
{
	ft_rotate_up(s_a, NULL);
	ft_rotate_up(s_b, NULL);
}

void	ft_rotate_down_all(t_lst **s_a, t_lst **s_b)
{
	ft_rotate_down(s_a, NULL);
	ft_rotate_down(s_b, NULL);
}
