/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egorafanasev <egorafanasev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:59:29 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/08 18:58:52 by egorafanase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	for_rrr_rr(t_stack **tmp)
{
	if (((*tmp)->score_ra) && ((*tmp)->score_rb))
	{
		while (((*tmp)->score_ra) && ((*tmp)->score_rb))
		{			
			(*tmp)->score_rr += 1;
			(*tmp)->score_rb -= 1;
			(*tmp)->score_ra -= 1;
		}
	}
	else if (((*tmp)->score_rra) && ((*tmp)->score_rrb))
	{
		while (((*tmp)->score_rra) && ((*tmp)->score_rrb))
		{
			(*tmp)->score_rrr += 1;
			(*tmp)->score_rrb -= 1;
			(*tmp)->score_rra -= 1;
		}
	}
}

void	t_stack_a(t_stack *head_a, int len_a, t_stack **tmp_b)
{
	t_stack	*tmp_a;
	int		i_ra;

	tmp_a = head_a;
	i_ra = 1;
	while (tmp_a->p)
	{
		if (((*tmp_b)->n < tmp_a->p->n) && ((*tmp_b)->n > tmp_a->n))
			break ;
		tmp_a = tmp_a->p;
		i_ra++;
	}
	if (i_ra < (len_a / 2))
		(*tmp_b)->score_ra = i_ra;
	else if (i_ra >= (len_a / 2) && i_ra != len_a)
		(*tmp_b)->score_rra = (len_a - i_ra);
	return ;
}

void	pushing(t_stack **head_a, t_stack **head_b, t_stack **tmp_b)
{
	while ((*tmp_b)->score_rrr--)
		rrr(&(*head_b), &(*head_a));
	while ((*tmp_b)->score_rr--)
		rr(&(*head_b), &(*head_a));
	while ((*tmp_b)->score_rb--)
		rb(&(*head_b));
	while ((*tmp_b)->score_rrb--)
		rrb(&(*head_b));
	while ((*tmp_b)->score_ra--)
		ra(&(*head_a));
	while ((*tmp_b)->score_rra--)
		rra(&(*head_a));
	pa(*(&head_a), *(&head_b));
}

void	for_rb(t_stack **tmp_b, int len_b, int i_rb)
{
	if (i_rb > len_b / 2)
		(*tmp_b)->score_rrb = (len_b - i_rb);
	else if (i_rb <= len_b / 2)
		(*tmp_b)->score_rb = i_rb;
}

void	select_b(t_stack **head_a, t_stack **head_b, int len_a, int len_b)
{
	int		i_rb;
	t_stack	*tmp_b;
	t_stack	*tmp_final;

	while (len_b)
	{
		i_rb = 0;
		tmp_b = (*head_b);
		while (tmp_b)
		{
			clean_score(&tmp_b);
			t_stack_a((*head_a), len_a, &tmp_b);
			for_rb(&tmp_b, len_b, i_rb);
			for_rrr_rr(&tmp_b);
			score_all(&tmp_b);
			if (i_rb == 0 || tmp_b->score_all < tmp_final->score_all)
				tmp_final = tmp_b;
			tmp_b = tmp_b->p;
			i_rb++;
		}
		pushing(*(&head_a), *(&head_b), &tmp_final);
		len_b--;
		len_a++;
	}	
}
