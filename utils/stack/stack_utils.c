/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 03:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:53:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->prev);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*current;
	int		size;

	if (!stack)
		return (0);
	size = 1;
	current = stack->next;
	while (current != stack)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	ft_stack_peek(t_stack *stack, int *value)
{
	if (!stack || !value)
		return (0);
	*value = stack->value;
	return (1);
}

void	ft_stack_append(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	if (!stack)
		return ;
	new_node = create_stack(value);
	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = (*stack)->prev;
	new_node->next = *stack;
	new_node->prev = last;
	last->next = new_node;
	(*stack)->prev = new_node;
}
