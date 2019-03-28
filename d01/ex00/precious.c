/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:47:36 by pstringe          #+#    #+#             */
/*   Updated: 2019/03/27 19:51:51 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
**	creates new circular doubly linked list node with content consisting of the
**	input character
*/

struct s_node	*new_node(char c)
{
	struct s_node *n;

	n = malloc(sizeof(struct s_node));
	n->c = c;
	//printf("create: %c\n", n->c);
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

/*
**	creates new circular doubly linked list with each nodes content consisting
** of one character in the input string
*/

circ	*new_list(char *str)
{
	circ *list;
	struct s_node *nw;
	int i;

	list = malloc(sizeof(circ));
	list->head = NULL;
	i = -1;
	while (str[++i])
	{
		nw = new_node(str[i]);
		if (!list->head)
		{
			list->head = nw;
			list->head->prev = list->head;
			list->head->next = list->head;
		}
		else
		{
			list->head->prev->next = nw;
			nw->prev = list->head->prev;
			nw->next = list->head;
			list->head->prev = nw;
		}
	}
	return (list);
}

/*
**	a function to rotate the list by shifting the head pointer "rot" times
**	and return the current value of head
*/

char	rotate(circ *lst, int rot)
{
	struct s_node *head;

	head = lst->head;
	if (rot > 0)
		while (rot--)
			head = head->next;
	else
		while (rot++ < 0)
			head = head->prev;
	lst->head = head;
	return (head->c);
			
}

char *precious(int *text, int size)
{
	int 	i;
	char 	*plain_text;
	circ 	*list;

	list = new_list(CS);
	plain_text = malloc(size + 1);
	bzero(plain_text, size + 1);
	
	for (i = 0; i < size; i++)
	{
		plain_text[i] = rotate(list, text[i]);
		printf("number: %d, rotated val: %c\n", text[i], plain_text[i]);
	}
	return (plain_text);
}


