/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:54 by pbomber           #+#    #+#             */
/*   Updated: 2021/10/26 00:01:49 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	num;
	int		i;

	i = 0;
	num = 0;
	while (*s)
	{
		s++;
		num++;
	}
	p = (char *)malloc(num + 1);
	if (!p)
		return (NULL);
	while (num + 1)
	{
		p[num] = *(char *)s;
		num--;
		s--;
	}
	return (p);
}
