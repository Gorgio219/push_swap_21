/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:59:29 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/19 22:32:07 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rtrn(void)
{
	write(2, "Error\n", 6);
	return (0);
}	

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		*arr_a;
	char	**arr_argv;

	arr_argv = check_argv(argc, argv);
	if (!arr_argv)
		return (rtrn());
	arr_a = rec_arr(arr_argv, len_argv(arr_argv));
	if (!arr_a)
		return (rtrn());
	head_a = rec_a(len_argv(arr_argv) - 1, arr_argv);
	sort_arr(arr_a, len_argv(arr_argv));
	if ((len_argv(arr_argv) - 1) > 3)
	{
		mmm(&head_a, &head_b, arr_a, len_argv(arr_argv));
		select_b(&head_a, &head_b, 3, len_argv(arr_argv) - 3);
	}
	sort_three(&head_a);
	final_sort(&head_a, arr_a[0], len_argv(arr_argv));
	free(arr_argv);
	free(arr_a);
	free(head_a);
	return (0);
}
