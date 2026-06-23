/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 by hvaini-d                  #+#    #+#             */
/*   Updated: 2026/06/23 by hvaini-d                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	sort_three(t_stack **stack_a, t_ops *ops)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = (*stack_a)->rank;
	b = (*stack_a)->next->rank;
	c = (*stack_a)->next->next->rank;
	if (a > b && b > c)
	{
		apply_swap(stack_a, ops);
		apply_reverse_rotate(stack_a, ops);
	}
	else if (a > c && c > b)
		apply_rotate(stack_a, ops);
	else if (b > a && a > c)
		apply_reverse_rotate(stack_a, ops);
	else if (a > b)
		apply_swap(stack_a, ops);
	else if (b > c)
	{
		apply_reverse_rotate(stack_a, ops);
		apply_swap(stack_a, ops);
	}
}

static void	push_min(t_stack **stack_a, t_stack **stack_b, t_ops *ops)
{
	t_stack			*index;
	unsigned int	min_rank;
	int				size;
	int				min_pos;
	int				i;

	size = ft_stack_size(*stack_a);
	index = *stack_a;
	min_rank = (*stack_a)->rank;
	min_pos = 0;
	i = 0;
	while (i < size)
	{
		if (index->rank < min_rank)
		{
			min_rank = index->rank;
			min_pos = i;
		}
		index = index->next;
		i++;
	}
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			apply_rotate(stack_a, ops);
	else
		while (min_pos++ < size)
			apply_reverse_rotate(stack_a, ops);
	apply_push(stack_a, stack_b, ops);
}

void	sort_five(t_stack **stack_a, t_ops *ops)
{
	t_stack	*stack_b;

	stack_b = NULL;
	push_min(stack_a, &stack_b, ops);
	push_min(stack_a, &stack_b, ops);
	sort_three(stack_a, ops);
	apply_push_back(&stack_b, stack_a, ops);
	apply_push_back(&stack_b, stack_a, ops);
}
