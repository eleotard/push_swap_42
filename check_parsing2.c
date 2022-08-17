/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:51:40 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/02 23:26:03 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_lst **alst)
{
	t_lst	*buff;
	t_lst	*cur;

	buff = *alst;
	while (buff)
	{
		cur = buff->next;
		while (cur)
		{
			if (buff->content == cur->content)
				return (ERROR);
			cur = cur->next;
		}
	buff = buff->next;
	}
	return (0);
}

int	ft_check_sort(t_lst **alst)
{
	t_lst	*buff;
	t_lst	*cur;

	buff = *alst;
	while (buff)
	{
		cur = buff->next;
		while (cur)
		{
			if (buff->content > cur->content)
				return (0);
			cur = cur->next;
		}
		buff = buff->next;
	}
	return (OK);
}
