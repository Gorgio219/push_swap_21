/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:59:29 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/19 22:27:38 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_stack **head)
{
	if (((*head)->p->p->n < (*head)->p->n && (*head)->p->p->n > (*head)->n)
		|| ((*head)->p->n < (*head)->n && (*head)->p->n > (*head)->p->p->n)
		|| ((*head)->n < (*head)->p->p->n && (*head)->n > (*head)->p->n))
		sa(&(*head));
}

void	sort_arr(int *arr_a, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 1;
	while (len)
	{
		while (j < len)
		{
			if (arr_a[i] > arr_a[j])
			{
				tmp = arr_a[i];
				arr_a[i] = arr_a[j];
				arr_a[j] = tmp;
			}
			i++;
			j++;
		}
		len--;
		i = 0;
		j = 1;
	}
}

void	final_sort(t_stack **head, int min, int len)
{
	t_stack	*tmp;
	int		i;

	tmp = (*head);
	if (!(*head))
		return ;
	i = 0;
	while (tmp->n != min)
	{
		tmp = tmp->p;
		i++;
	}
	if (i <= (len / 2))
	{
		while (i--)
			ra(&(*head));
	}
	else if (i > (len / 2))
	{
		i = len - i;
		while (i--)
			rra(&(*head));
	}
}
