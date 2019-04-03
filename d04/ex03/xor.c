/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:55:37 by pstringe          #+#    #+#             */
/*   Updated: 2019/04/02 19:09:30 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	toInt(char *a)
{
	int i;
	int n;
	int weight;
	int sum;

	n = 1;
	if (a[0] == '-' && ++a)
		n = -1;
	i = strlen(a);
	sum = 0;
	weight = 1;
	while (--i > 0){
		sum += (a[i] - '0') * weight;
		weight *= 2;
	}
	return (sum * n);
}

char *getXor(char *a, char *b)
{
	int i;
	char *r;
	i = -1;
	
	r = malloc(7);
	bzero(r, 7);
	while (++i < 6)
		r[i] = a[i] != b[i] ? '1' : '0';
	return (r);
}
