/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:20:46 by pstringe          #+#    #+#             */
/*   Updated: 2019/03/27 20:59:30 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *s;

	s = malloc(sizeof(struct s_stack));
	s->item = NULL;
	return (s);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *item;

	item = malloc(sizeof(struct s_item));
	item->word = strdup(word);
	item->next = stack->item;
	stack->item = item;
}

void *pop(struct s_stack *stack)
{
	struct s_item *item;

	item = stack->item;
	stack->item = stack->item->next;
	item->next = NULL;
	return ((void*)item);
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack 	*stack;
	struct s_node	*tmp;

	stack = stackInit();
	/*push list items to stack*/
	tmp = lst;
	while (tmp){
		//printf("push: %s\n", tmp->word);
		push(stack, tmp->word);
		//printf("top: %s\n", stack->item->word);
		tmp = tmp->next;
	}

	/*pop and print*/
	while (stack->item)
		printf("%s ", ((struct s_item*)pop(stack))->word);
}
