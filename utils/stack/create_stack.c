/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:48:10 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 16:48:30 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

t_stack	*create_stack(int value)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->rank = UINT_MAX;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

int	ft_pop(t_stack **stack, int *value)
{
	t_stack	*node;

	if (!stack || !*stack)
		return (0);
	node = *stack;
	if (value)
		*value = node->value;
	if (node->next == node)
		*stack = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*stack = node->next;
	}
	free(node);
	return (1);
}
