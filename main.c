/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:07:24 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/26 16:19:59 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_lst	*ft_init_stack_a(char **argv)
{
	int		i;
	int		k;
	char	**tab;
	t_lst	*s_a;

	k = -1;
	i = 0;
	s_a = NULL;
	while (argv[++i])
	{
		tab = ft_split(argv[i], ' ');
		if (!tab)
			return (NULL);
		while (tab[++k])
			ft_lst_addback_p(&s_a, ft_lstnew_p(ft_atoi(tab[k])), tab);
		tab = ft_free_tab(tab);
		k = -1;
	}
	if (ft_check_duplicates(&s_a) == ERROR)
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear_p(&s_a);
		return (NULL);
	}
	return (s_a);
}

void	ft_push_swap(t_lst **s_a, t_lst **s_b)
{
	int	lstsize;
	int	mediane;

	mediane = ft_find_mediane(s_a, s_b);
	lstsize = ft_lstsize_p(s_a);
	if (lstsize == 2)
		ft_sort_two(s_a);
	else if (lstsize == 3)
		ft_sort_three(s_a);
	else if (lstsize == 5)
		ft_sort_five(s_a, s_b);
	else if (lstsize > 3)
		ft_sort_algo(s_a, s_b, mediane);
	ft_free_lst_ok(s_a, NULL);
}

int	main(int argc, char **argv)
{
	t_lst	*s_a;
	t_lst	*s_b;

	s_b = NULL;
	if (ft_check_parsing(argc, argv) == ERROR)
		return (0);
	s_a = ft_init_stack_a(argv);
	if (!s_a)
		return (0);
	if (ft_check_sort(&s_a) == OK || ft_lstsize_p(&s_a) == 1)
	{
		ft_lstclear_p(&s_a);
		return (0);
	}
	ft_push_swap(&s_a, &s_b);
	ft_lstclear_p(&s_a);
	ft_lstclear_p(&s_b);
	return (0);
}
