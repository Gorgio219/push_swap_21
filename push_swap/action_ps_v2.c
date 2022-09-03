/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ps_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:56:15 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/07 19:56:47 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	tmp = *head_b;
	*head_b = (*head_b)->p;
	tmp->p = *head_a;
	*head_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = (*head_a)->p;
	tmp_b = (*head_a);
	tmp_b->p = (*head_b);
	(*head_b) = tmp_b;
	(*head_a) = tmp_a;
	write(1, "pb\n", 3);
}

void	ra(t_stack **head_a)
{
	t_stack	*tmp_start;
	t_stack	*tmp_end;

	if ((*head_a)->p == NULL || *head_a == NULL)
		return ;
	tmp_start = *head_a;
	while ((*head_a)->p != NULL)
		*head_a = (*head_a)->p;
	tmp_end = *head_a;
	*head_a = tmp_start->p;
	tmp_start->p = tmp_end->p;
	tmp_end->p = tmp_start;
	write(1, "ra\n", 3);
}

void	rb(t_stack **head_b)
{
	t_stack	*tmp_start;
	t_stack	*tmp_end;

	if ((*head_b)->p == NULL || *head_b == NULL)
		return ;
	tmp_start = *head_b;
	while ((*head_b)->p != NULL)
		*head_b = (*head_b)->p;
	tmp_end = *head_b;
	*head_b = tmp_start->p;
	tmp_start->p = tmp_end->p;
	tmp_end->p = tmp_start;
	write(1, "rb\n", 3);
}

void	rra(t_stack **head_a)
{
	t_stack	*tmp_start;
	t_stack	*tmp_end;

	if ((*head_a)->p == NULL || *head_a == NULL)
		return ;
	tmp_start = *head_a;
	while ((*head_a)->p->p != NULL)
		*head_a = (*head_a)->p;
	tmp_end = *head_a;
	*head_a = (*head_a)->p;
	tmp_end->p = (*head_a)->p;
	(*head_a)->p = tmp_start;
	write(1, "rra\n", 4);
}
