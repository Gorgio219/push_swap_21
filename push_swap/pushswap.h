/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:48:56 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/11 19:13:49 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h" 

typedef struct stack
{
	int				n;
	int				score_ra;
	int				score_rb;
	int				score_rra;
	int				score_rrb;
	int				score_rr;
	int				score_rrr;
	int				score_sb;
	int				score_all;
	struct stack	*p;
}	t_stack;

void	pa(t_stack **head_a, t_stack **head_b);
void	pb(t_stack **head_a, t_stack **head_b);
void	ra(t_stack **head_a);
void	rb(t_stack **head_b);
void	rra(t_stack **head_a);
void	rrb(t_stack **head_b);
void	rr(t_stack **head_a, t_stack **head_b);
void	rrr(t_stack **head_a, t_stack **head_b);
void	sb(t_stack **head);
void	sa(t_stack **head);

int		check_in(int i, char **str);
char	**check_argv(int argc, char *argv[]);
int		*rec_arr(char *tmp_a[], int len);
int		len_argv(char **tmp);

t_stack	*rec_a(int argc, char *argv[]);
void	score_all(t_stack **tmp_b);
void	create_node_a(t_stack **head, int data);
void	clean_score(t_stack **tmp_b);
void	mmm(t_stack **head_a, t_stack **head_b, int arr_a[], int len);

void	sort_arr(int arr_a[], int len);
void	final_sort(t_stack **head, int max, int len);
void	sort_three(t_stack **head);

void	select_b(t_stack **head_a, t_stack **head_b, int len_a, int len_b);
void	t_stack_analiz_a(t_stack *head_a, int len_a, t_stack **tmp_b);
void	swap_b(t_stack **tmp_b, t_stack *head_b, int len_b);
void	for_rrr(t_stack **tmp);
void	for_rb(t_stack **tmp_b, int len_b, int i_rb);

#endif