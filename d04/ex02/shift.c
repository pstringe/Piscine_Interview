/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:19:50 by pstringe          #+#    #+#             */
/*   Updated: 2019/04/02 18:47:16 by pstringe         ###   ########.fr       */
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
	return (sum * 1);
}

char *rightShift(char *bin, int k)
{
	int i;
	
	k = k * -1;
	i = 6;
	while (--i >= 0)
		bin[i] = i + k >= 0 && i + k < 6 ? bin[i + k] : '0';
	return (bin);
}

char *leftShift(char *bin, int k)
{
	int i;

	i = -1;
	while (++i < 6)
		bin[i] = i + k >= 0 && i + k < 6 ? bin[i + k] : '0';
	return (bin);
}
