/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:58:27 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/11 17:49:41 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_p(t_lst **alst)
{
	t_lst	*buff;
	int		lst_size;

	if (!*alst)
		return (0);
	lst_size = 0;
	buff = *alst;
	while (buff)
	{
		buff = buff->next;
		lst_size++;
	}
	return (lst_size);
}

t_lst	*ft_lstnew_p(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lst_addback_p(t_lst **alst, t_lst *new, char **tab)
{
	t_lst	*buff;

	if (!alst)
		return ;
	if (!new)
	{
		tab = ft_free_tab(tab);
		ft_lstclear_p(alst);
		exit (-1);
	}
	if (*alst)
	{
		buff = *alst;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = new;
	}
	else
		*alst = new;
}
