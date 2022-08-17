/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:11:32 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/26 15:46:03 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "ft_printf/libprintf.h"
# include "gnl/get_next_line.h"

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

# define ERROR -1
# define OK 1

typedef struct s_data
{
	int		i;
	int		j;
	int		k;
	char	**tab;
}	t_data;

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
}	t_lst;

/*CHECK CORRECT INPUT*/
int		ft_check_parsing(int argc, char **argv);
int		ft_atoi_max(const char *nptr);
int		ft_check_correct_caracters(char **argv);
int		ft_check_correct_int(char **argv);
int		ft_check_is_digit(t_data *va);
int		ft_check_overflow(char **str);
int		ft_check_duplicates(t_lst **alst);
int		ft_check_sort(t_lst **alst);

/*LIST MATERIAL*/
t_lst	*ft_lstnew_p(int content);
void	ft_lst_addback_p(t_lst **alst, t_lst *new, char **tab);

int		ft_lstsize_p(t_lst **alst);

/*MOOVES*/
void	ft_swap_lst(t_lst *begin, char *s_name);
void	ft_rotate_up(t_lst **alst, char *s_name);
void	ft_rotate_down(t_lst **alst, char *s_name);

void	ft_swap_all(t_lst **s_a, t_lst **s_b);
void	ft_rotate_up_all(t_lst **s_a, t_lst **s_b);
void	ft_rotate_down_all(t_lst **s_a, t_lst **s_b);

void	ft_push_a(t_lst **s_a, t_lst **s_b);
void	ft_push_b(t_lst **s_a, t_lst **s_b);

/*FREE*/
char	**ft_free_tab(char **tab);
int		ft_lstclear_p(t_lst **lst);

/*BONUS*/
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_p(char *base, char *read);
char	*join_p(char *base, char *read);
t_lst	*ft_init_stack_a(char **argv);
void	ft_check_ok_ko(t_lst **s_a, t_lst **s_b);

#endif