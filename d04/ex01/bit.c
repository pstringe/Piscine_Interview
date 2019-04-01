/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:56:41 by pstringe          #+#    #+#             */
/*   Updated: 2019/04/01 13:17:33 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int	toInt(char *a)
{
	int i;
	int weight;
	int sum;

	i = strlen(a);
	sum = 0;
	weight = 1;
	while (--i > 0){
		sum += (a[i] - '0') * weight;
		weight *= 2;
	}
	return (sum);
}

char *getAnd(char *a, char *b)
{
	char	*r;
	int		i;
	int 	anot;
	int 	bnot;

	r = malloc(5);
	bzero(r, 5);
	i = 4;

	anot = a[0]  == '~' ? 1 : 0;
	bnot = b[0]  == '~' ? 1 : 0;
	a = anot ? a + 1 : a;
	b = bnot ? b + 1 : b;
	while(--i >= 0)
		 r[i] = (anot ? !(a[i] - '0') : a[i] - '0') && 
			 	(bnot ? !(b[i] - '0') : b[i] - '0') 
				? '1' : '0';
	return (r);
}

char *getOr(char *a, char *b)
{
	char	*r;
	int		i;
	int 	anot;
	int 	bnot;

	r = malloc(5);
	bzero(r, 5);
	i = 4;

	anot = a[0]  == '~' ? 1 : 0;
	bnot = b[0]  == '~' ? 1 : 0;
	a = anot ? a + 1 : a;
	b = bnot ? b + 1 : b;
	while(--i >= 0)
		 r[i] = (anot ? !(a[i] - '0') : a[i] - '0') || 
			 	(bnot ? !(b[i] - '0') : b[i] - '0') 
				? '1' : '0';
	return (r);
}
