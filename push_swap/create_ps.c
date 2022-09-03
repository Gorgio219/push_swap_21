/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:57:57 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/11 18:49:35 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	mmm(t_stack **head_a, t_stack **head_b, int arr_a[], int len)
{
	int	max;

	max = len - 1;
	while (len > 3)
	{
		if ((*head_a)->n == arr_a[0] || (*head_a)->n == arr_a[max]
			|| (*head_a)->n == arr_a[(max / 2)])
		{
			ra(&(*head_a));
		}
		else
		{
			pb(&(*head_a), &(*head_b));
			len--;
		}
	}
	sort_three(head_a);
}

void	create_node_a(t_stack **head, int data)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	tmp->n = data;
	tmp->score_ra = 0;
	tmp->score_rb = 0;
	tmp->score_rra = 0;
	tmp->score_rrb = 0;
	tmp->score_rr = 0;
	tmp->score_rrr = 0;
	tmp->score_all = 0;
	tmp->p = (*head);
	(*head) = tmp;
}

void	clean_score(t_stack **tmp)
{
	(*tmp)->score_ra = 0;
	(*tmp)->score_rb = 0;
	(*tmp)->score_rra = 0;
	(*tmp)->score_rrb = 0;
	(*tmp)->score_rr = 0;
	(*tmp)->score_rrr = 0;
}

t_stack	*rec_a(int argc, char *argv[])
{
	t_stack	*head;

	head = NULL;
	while (argc >= 0)
	{
		create_node_a(&head, ft_atoi(argv[argc]));
		argc--;
	}
	return (head);
}

void	score_all(t_stack **tmp_b)
{
	(*tmp_b)->score_all = (*tmp_b)->score_ra + (*tmp_b)->score_rb
		+ (*tmp_b)->score_rrb + (*tmp_b)->score_rra + (*tmp_b)->score_rr
		+ (*tmp_b)->score_rrr;
}
