/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:06:47 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/24 17:14:42 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstclear_p(t_lst **lst)
{
	t_lst	*buff;
	t_lst	*buff_tmp;

	if (*lst == NULL)
		return (0);
	buff_tmp = NULL;
	buff = *lst;
	while (buff)
	{
		buff_tmp = buff;
		buff = buff->next;
		free(buff_tmp);
		buff_tmp = NULL;
	}
	return (0);
}

char	**ft_free_tab(char **tab)
{
	int	k;

	k = 0;
	while (tab[k])
		k++;
	while (k >= 0)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
	return (NULL);
}

void	ft_free_tabs_lst_exit(t_lst **s_a, int *tab, int *tab_cpy,
	int *tab_index)
{
	if (tab)
		free(tab);
	if (tab_cpy)
		free(tab_cpy);
	if (tab_index)
		free(tab_index);
	if (s_a)
		ft_lstclear_p(s_a);
	exit(-1);
}

void	ft_free_tabs(int *tab, int *tab_cpy, int *tab_index)
{
	if (tab)
		free(tab);
	if (tab_cpy)
		free(tab_cpy);
	if (tab_index)
		free(tab_index);
}
