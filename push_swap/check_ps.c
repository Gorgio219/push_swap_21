/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:04:51 by pbomber           #+#    #+#             */
/*   Updated: 2022/02/19 22:13:41 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_in(int i, char **str)
{	
	int	j;

	j = 0;
	while (i)
	{
		if (!(str[i][j] >= '0' && str[i][j] <= '9') && !(str[i][j] == 45))
			return (0);
		else if ((str[i][j] == 45) && (!(str[i][1]) ||
			!(str[i][1] >= '0' && str[i][1] <= '9')))
			return (0);
		else
		{
			j++;
			while (str[i][j])
			{
				if (!(str[i][j] >= '0' && str[i][j] <= '9'))
					return (0);
				j++;
			}
			j = 0;
		}
		i--;
	}
	return (1);
}

int	len_argv(char **tmp)
{
	int	i;

	i = 1;
	while (tmp[i])
	{
		i++;
	}
	return (i);
}

int	*rec_arr(char *tmp_a[], int len)
{
	int	i;
	int	j;
	int	*arr;

	i = -1;
	j = 0;
	arr = malloc(sizeof(int) * (len_argv(tmp_a)));
	while (len)
	{
		i++;
		arr[i] = ft_atoi(tmp_a[len - 1]);
		while (j < i)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				return (NULL);
			}
			j++;
		}
		j = 0;
		len--;
	}
	return (arr);
}

char	**check_argv(int argc, char *argv[])
{
	int		i;
	char	*tmp;
	char	**tmp_a;

	tmp = malloc(sizeof(char) * 1);
	if (argc == 1)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!ft_strlen(argv[i]))
			return (NULL);
		tmp = ft_strjoin(tmp, argv[i]);
		i++;
	}
	tmp_a = ft_split(tmp, ' ');
	if (!(check_in(len_argv(tmp_a) - 1, tmp_a)))
		return (NULL);
	free(tmp);
	return (tmp_a);
}
