/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:05:22 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	fill_ranks(int *ranks, t_stack *stack, int size)
{
	t_stack	*node;
	int		i;

	node = stack;
	i = 0;
	while (i < size)
	{
		ranks[i] = node->rank;
		node = node->next;
		i++;
	}
}

static int	*compute_chain_len(int *ranks, int *prev_pos, int size)
{
	int	*chain_len;
	int	i;
	int	j;

	chain_len = ft_calloc(size, sizeof(int));
	if (!chain_len)
		return (NULL);
	i = 0;
	while (i < size)
	{
		chain_len[i] = 1;
		prev_pos[i] = -1;
		j = 0;
		while (j < i)
		{
			if (ranks[j] < ranks[i] && chain_len[j] + 1 > chain_len[i])
			{
				chain_len[i] = chain_len[j] + 1;
				prev_pos[i] = j;
			}
			j++;
		}
		i++;
	}
	return (chain_len);
}

static int	*build_in_lis(t_stack *stack_a, int size)
{
	int	*ranks;
	int	*chain_len;
	int	*prev_pos;
	int	*in_lis;

	ranks = ft_calloc(size, sizeof(int));
	prev_pos = ft_calloc(size, sizeof(int));
	if (!ranks || !prev_pos)
		return (free(ranks), free(prev_pos), NULL);
	fill_ranks(ranks, stack_a, size);
	chain_len = compute_chain_len(ranks, prev_pos, size);
	if (!chain_len)
		return (free(ranks), free(prev_pos), NULL);
	in_lis = mark_lis(chain_len, prev_pos, ranks, size);
	free(ranks);
	free(chain_len);
	free(prev_pos);
	return (in_lis);
}

void	lis_sort(t_stack **stack_a, t_ops *ops)
{
	t_stack	*stack_b;
	int		*in_lis;
	int		size;

	stack_b = NULL;
	in_lis = build_in_lis(*stack_a, ft_stack_size(*stack_a));
	if (!in_lis)
		return ;
	push_non_lis(stack_a, &stack_b, in_lis, ops);
	free(in_lis);
	while (stack_b)
		insert_element(stack_a, &stack_b, find_best(stack_a, &stack_b), ops);
	size = ft_stack_size(*stack_a);
	turn_to_top(stack_a, min_pos(*stack_a, size), size, ops);
}
