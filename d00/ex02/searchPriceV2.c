/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:43:46 by pstringe          #+#    #+#             */
/*   Updated: 2019/03/26 23:18:09 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"
#include <string.h>

int bsearch(void **arr, int l, int r, char *name) 
{ 
	int mid;
    if (r >= l) { 
        mid = l + (r - l) / 2; 
        if (!strcmp(((struct s_art*)arr[mid])->name, name)) 
            return mid; 
        if (strcmp(((struct s_art*)arr[mid])->name, name) > 0) 
            return bsearch(arr, l, mid - 1, name); 
        return bsearch(arr, mid + 1, r, name); 
    } 
    return (-1); 
} 

int	searchPrice(struct s_art **arts, int n, char *name)
{
	int				loc;

	if ((loc = bsearch((void**)arts, 0, n, name)) >= 0)
		return (arts[loc]->price);
	return(loc);
}
