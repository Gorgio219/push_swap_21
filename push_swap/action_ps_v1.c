/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ps_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:56:02 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/07 19:56:04 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrb(t_stack **head_b)
{
	t_stack	*tmp_start;
	t_stack	*tmp_end;

	if ((*head_b)->p == NULL || *head_b == NULL)
		return ;
	tmp_start = *head_b;
	while ((*head_b)->p->p != NULL)
		*head_b = (*head_b)->p;
	tmp_end = *head_b;
	*head_b = (*head_b)->p;
	tmp_end->p = (*head_b)->p;
	(*head_b)->p = tmp_start;
	write(1, "rrb\n", 4);
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	ra(&(*head_a));
	rb(&(*head_b));
	write(1, "rr\n", 3);
}

void	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(&(*head_a));
	rrb(&(*head_b));
	write(1, "rrr\n", 4);
}

void	sa(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->p;
	tmp->p = tmp->p->p;
	(*head)->p = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->p;
	tmp->p = tmp->p->p;
	(*head)->p = tmp;
	write(1, "sb\n", 3);
}
