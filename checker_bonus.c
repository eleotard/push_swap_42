/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:55:39 by eleotard          #+#    #+#             */
/*   Updated: 2022/09/05 22:53:20 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_do_command(t_lst **s_a, t_lst **s_b, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_rotate_up(s_a, NULL);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate_up(s_b, NULL);
	else if (ft_strcmp(line, "pa") == 0)
		ft_push_a(s_a, s_b);
	else if (ft_strcmp(line, "pb") == 0)
		ft_push_b(s_a, s_b);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rotate_up_all(s_a, s_b);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rotate_down(s_a, NULL);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rotate_down(s_b, NULL);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rotate_down_all(s_a, s_b);
	else if (ft_strcmp(line, "sa") == 0)
		ft_swap_lst(*s_a, NULL);
	else if (ft_strcmp(line, "sb") == 0)
		ft_swap_lst(*s_b, NULL);
	else if (ft_strcmp(line, "ss") == 0)
		ft_swap_all(s_a, s_b);
}

char	*create_read_str(void)
{
	char	*str;
	char	*tmp;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	tmp = malloc(sizeof(char) * 1);
	if (!tmp)
		return (free(str), NULL);
	tmp[0] = '1';
	while (ft_strcmp(tmp, str) != 0)
	{
		tmp = ft_free(tmp, NULL);
		tmp = ft_strdup(str);
		str = join_p(str, get_next_line(0));
		if (!str)
			return (free(tmp), NULL);
	}
	free(tmp);
	return (str);
}

char	**ft_create_check_tab(char *line)
{
	char	**tab;
	int		k;

	k = 0;
	tab = ft_split(line, '\n');
	if (!tab)
		return (NULL);
	while (tab[k])
	{
		if (ft_strcmp(tab[k], "sa") == 0 || ft_strcmp(tab[k], "sb") == 0
			|| ft_strcmp(tab[k], "ra") == 0 || ft_strcmp(tab[k], "rb") == 0
			|| ft_strcmp(tab[k], "rra") == 0 || ft_strcmp(tab[k], "rrb") == 0
			|| ft_strcmp(tab[k], "rr") == 0 || ft_strcmp(tab[k], "rrr") == 0
			|| ft_strcmp(tab[k], "pa") == 0 || ft_strcmp(tab[k], "pb") == 0
			|| ft_strcmp(tab[k], "ss") == 0)
			k++;
		else
		{
			ft_putstr_fd("\nError\n", 2);
			ft_free_tab(tab);
			return (NULL);
		}
	}
	return (tab);
}

void	ft_read_tab_and_free(t_lst **s_a, t_lst **s_b, char **tab, char *line)
{
	int	k;

	k = -1;
	while (tab[++k])
		ft_do_command(s_a, s_b, tab[k]);
	ft_check_ok_ko(s_a, s_b);
	free(line);
	ft_free_tab(tab);
	ft_lstclear_p(s_a);
	ft_lstclear_p(s_b);
}

int	main(int argc, char **argv)
{
	t_lst		*s_a;
	t_lst		*s_b;
	char		*line;
	char		**tab;

	s_b = NULL;
	if (ft_check_parsing(argc, argv) == ERROR)
		return (0);
	s_a = ft_init_stack_a(argv);
	if (!s_a)
		return (0);
	if (ft_check_sort(&s_a) == OK || ft_lstsize_p(&s_a) == 1)
		return (ft_putstr_fd("OK\n", 1), ft_lstclear_p(&s_a));
	line = create_read_str();
	if (!line)
		return (ft_lstclear_p(&s_a));
	tab = ft_create_check_tab(line);
	if (!tab)
	{
		free(line);
		return (ft_lstclear_p(&s_a));
	}
	ft_read_tab_and_free(&s_a, &s_b, tab, line);
	return (0);
}
