/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 03:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:53:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stack_contains(t_stack *stack, int value)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (1)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}

int	ft_stack_min(t_stack *stack, int *min_value)
{
	t_stack	*current;

	if (!stack || !min_value)
		return (0);
	*min_value = stack->value;
	current = stack->next;
	while (current != stack)
	{
		if (current->value < *min_value)
			*min_value = current->value;
		current = current->next;
	}
	return (1);
}

int	ft_stack_max(t_stack *stack, int *max_value)
{
	t_stack	*current;

	if (!stack || !max_value)
		return (0);
	*max_value = stack->value;
	current = stack->next;
	while (current != stack)
	{
		if (current->value > *max_value)
			*max_value = current->value;
		current = current->next;
	}
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*current;
	int		size;
	int		i;

	if (!stack)
		return (1);
	size = ft_stack_size(stack);
	current = stack;
	i = 0;
	while (i < size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
