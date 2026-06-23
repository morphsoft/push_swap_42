/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:47:03 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:10:08 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	normalize_stack(t_stack *stack)
{
	t_stack	*tochange;
	t_stack	*index;
	long	max_size;
	int		maximum;

	max_size = ft_stack_size(stack);
	index = stack;
	maximum = stack->value;
	while (max_size > 0)
	{
		if (maximum <= index->value && index->rank == UINT_MAX)
		{
			maximum = index->value;
			tochange = index;
		}
		if (index->next)
			index = index->next;
		else
		{
			tochange->rank = --max_size;
			maximum = INT_MIN;
			index = stack;
		}
	}
}
