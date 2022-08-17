/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:11:32 by eleotard          #+#    #+#             */
/*   Updated: 2022/06/29 17:48:22 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/libprintf.h"

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

# define ERROR -1
# define OK 1
# define RA 2
# define RRA 3

typedef struct s_tab
{
	int	*tab;
	int	*tab_cpy;
	int	*tab_index;
	int	*tab_sequence;
	int	size_sequence;
}	t_tab;

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

/*MAIN*/
t_lst	*ft_init_stack_a(char **argv);

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

/*MEDIANE STUFF*/
int		*ft_cpy_list_in_tab(t_lst **s_a, int size);
void	ft_swap(int *a, int *b);
void	ft_sort_tab(int *tab, int size);
int		*ft_create_sorted_tab(t_lst **s_a, t_lst **s_b, int size);
int		ft_find_mediane(t_lst **s_a, t_lst **s_b);

/*SORT STUFF*/
t_lst	**ft_sort_two(t_lst **s_a);
t_lst	**ft_sort_three(t_lst **s_a);
t_lst	**ft_sort_five(t_lst **s_a, t_lst **s_b);
int		ft_find_strict_superior(t_lst **s_a, int number_b);
int		ft_count_moves(t_lst **s_a, int number_b);
int		ft_find_min_lst(t_lst **s_a);
int		ft_rotation_direction(t_lst **s_a, int number_b);
void	ft_rotate_correctly(t_lst **s_a, int content);
void	ft_rotate_when_done(t_lst **s_a, int min);

/*SORT ALGO*/
t_lst	**ft_sort_algo(t_lst **s_a, t_lst **s_b, int mediane);
void	ft_push_all_b_except_sequence(t_lst **s_a, t_lst **s_b, int mediane);
void	ft_target_nb_to_move(t_lst **s_a, t_lst **s_b, int pos_s_b, int j);
int		ft_find_content_in_sequence(int content, t_tab *va);
int		*ft_create_tab_moves(t_lst **s_a, t_lst **s_b);
int		ft_find_pos_nbr(t_lst **stack, int nbr);
int		ft_find_index_min(int *tab, int size);
int		ft_count(int pos_s_a, int pos_s_b);
void	ft_do_moves(t_lst **s_a, t_lst **s_b, int pos_s_a, int pos_s_b);

void	ft_sort_pos_up_down(t_lst **s_a, t_lst **s_b, int pos_s_a, int pos_s_b);
void	ft_sort_pos_up_up(t_lst **s_a, t_lst **s_b, int pos_s_a, int pos_s_b);
void	ft_sort_pos_down_down(t_lst **s_a, t_lst **s_b, int pos_s_a,
			int pos_s_b);

/*FREE*/
char	**ft_free_tab(char **tab);
int		ft_lstclear_p(t_lst **lst);
void	ft_free_tabs(int *tab, int *tab_cpy, int *tab_index);
void	ft_free_tabs_lst_exit(t_lst **s_a, int *tab, int *tab_cpy,
			int *tab_index);
void	ft_free_lst_ok(t_lst **s_a, t_lst **s_b);
void	ft_free_lst_exit(t_lst **s_a, t_lst **s_b);

/*SUBSEQUENCE*/
void	ft_find_subsequence(t_lst **s_a, t_tab *va, int size);
int		ft_find_min_tab(int *tab, int size);
int		ft_find_max_tab(int *tab, int size);
void	ft_create_tab_sequence(t_lst **s_a, t_tab *va, int size);
void	ft_init_struct_tab(t_tab *va, t_lst **s_a, int size);
int		*ft_calloc_tabs(int size, int nb);
void	ft_put_min_on_top(t_lst **s_a);

#endif