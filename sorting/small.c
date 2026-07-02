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
