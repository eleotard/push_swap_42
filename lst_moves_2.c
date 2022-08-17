/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_moves_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:15:11 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/08 02:04:33 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_all(t_lst **s_a, t_lst **s_b)
{
	ft_swap_lst(*s_a, "s");
	ft_swap_lst(*s_b, NULL);
}

void	ft_rotate_up_all(t_lst **s_a, t_lst **s_b)
{
	ft_rotate_up(s_a, "r");
	ft_rotate_up(s_b, NULL);
}

void	ft_rotate_down_all(t_lst **s_a, t_lst **s_b)
{
	ft_rotate_down(s_a, "r");
	ft_rotate_down(s_b, NULL);
}
