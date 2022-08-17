/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:06:47 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/09 01:06:01 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst_exit(t_lst **s_a, t_lst **s_b)
{
	if (s_a)
		ft_lstclear_p(s_a);
	if (s_b)
		ft_lstclear_p(s_b);
	exit (-1);
}

void	ft_free_lst_ok(t_lst **s_a, t_lst **s_b)
{
	if (s_a)
		ft_lstclear_p(s_a);
	if (s_b)
		ft_lstclear_p(s_b);
	exit (0);
}
