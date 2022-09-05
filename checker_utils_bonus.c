/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:55:39 by eleotard          #+#    #+#             */
/*   Updated: 2022/09/05 22:48:18 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_check_ok_ko(t_lst **s_a, t_lst **s_b)
{
	if ((ft_check_sort(s_a) == OK) && (*s_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strjoin_p(char *base, char *read)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!base || !read)
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen(base) + ft_strlen(read) + 1));
	if (!line)
		return (NULL);
	while (base[i])
	{
		line[i] = base[i];
		i++;
	}
	while (read[j])
	{
		line[i] = read[j];
		i++;
		j++;
	}
	line[i] = '\0';
	free(base);
	return (line);
}

char	*join_p(char *base, char *read)
{
	char	*new_read;

	if (!read)
	{
		read = malloc(sizeof(char));
		if (!read)
			return (free(base), NULL);
		read[0] = '\0';
	}
	new_read = ft_strjoin_p(base, read);
	if (!new_read)
		return (free(read), free(base), NULL);
	free(read);
	return (new_read);
}
