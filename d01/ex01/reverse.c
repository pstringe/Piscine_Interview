/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revearse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:59:46 by pstringe          #+#    #+#             */
/*   Updated: 2019/03/27 20:08:54 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
	if (lst->next == NULL)
		printf("%s", lst->word);
	else
	{
		printReverse(lst->next);
		printf(" %s", lst->word);
	}
}
