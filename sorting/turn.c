/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:52:49 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:06:58 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	turn_to_top(t_stack **stk, int pos, int size, t_ops *ops)
{
	if (pos <= size / 2)
		while (pos-- > 0)
			apply_rotate(stk, ops);
	else
		while (pos++ < size)
			apply_reverse_rotate(stk, ops);
}

int	min_pos(t_stack *stk, int size)
{
	t_stack			*node;
	unsigned int	best;
	int				pos;
	int				i;

	node = stk;
	best = stk->rank;
	pos = 0;
	i = 0;
	while (i < size)
	{
		if (node->rank < best)
		{
			best = node->rank;
			pos = i;
		}
		node = node->next;
		i++;
	}
	return (pos);
}

int	rank_pos(t_stack *stk, unsigned int rank, int size)
{
	t_stack	*node;
	int		i;

	node = stk;
	i = 0;
	while (i < size)
	{
		if (node->rank == rank)
			return (i);
		node = node->next;
		i++;
	}
	return (0);
}
