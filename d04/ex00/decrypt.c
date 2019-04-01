/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:08:23 by pstringe          #+#    #+#             */
/*   Updated: 2019/04/01 12:37:32 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	toInt(char *a)
{
	int i;
	int weight;
	int sum;

	i = 6;
	sum = 0;
	weight = 1;
	while (--i > 0){
		sum += (a[i] - '0') * weight;
		weight *= 2;
	}
	return (sum);
}

char *getSum(char *a, char *b)
{
	char	*r;
	int		s;
	int		c;
	int		i;

	r = malloc(7);
	bzero(r, 7);
	i = 6;
	while(--i >= 0)
	{
		 s = (a[i] - '0') + (b[i] - '0') + c;
		 c = s > 1 ? 1 : 0;
		 r[i] = s % 2 ? '1' : '0';
	}
	return (r);
}
