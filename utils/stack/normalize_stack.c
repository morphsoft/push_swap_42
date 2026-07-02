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
#include <stddef.h>

static t_stack	*max_unranked(t_stack *stack, int size)
{
	t_stack	*index;
	t_stack	*best;
	int		i;

	index = stack;
	best = NULL;
	i = 0;
	while (i < size)
	{
		if (index->rank == UINT_MAX && (!best || index->value > best->value))
			best = index;
		index = index->next;
		i++;
	}
	return (best);
}

void	normalize_stack(t_stack *stack)
{
	t_stack			*node;
	int				size;
	unsigned int	rank;

	if (!stack)
		return ;
	size = ft_stack_size(stack);
	rank = (unsigned int)size;
	while (rank > 0)
	{
		node = max_unranked(stack, size);
		if (!node)
			break ;
		rank--;
		node->rank = rank;
	}
}
