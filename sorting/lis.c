/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 by hvaini-d                  #+#    #+#             */
/*   Updated: 2026/06/23 by hvaini-d                 ###   ########.fr       */
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

static int	*compute_dp(int *ranks, int *parent, int size)
{
	int	*dp;
	int	i;
	int	j;

	dp = ft_calloc(size, sizeof(int));
	if (!dp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dp[i] = 1;
		parent[i] = -1;
		j = 0;
		while (j < i)
		{
			if (ranks[j] < ranks[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
			j++;
		}
		i++;
	}
	return (dp);
}

static int	*mark_lis(int *dp, int *parent, int *ranks, int size)
{
	int	*in_lis;
	int	max_len;
	int	idx;
	int	i;

	in_lis = ft_calloc(size, sizeof(int));
	if (!in_lis)
		return (NULL);
	max_len = 0;
	idx = 0;
	i = 0;
	while (i < size)
	{
		if (dp[i] > max_len)
		{
			max_len = dp[i];
			idx = i;
		}
		i++;
	}
	while (idx != -1)
	{
		in_lis[ranks[idx]] = 1;
		idx = parent[idx];
	}
	return (in_lis);
}

static int	*build_in_lis(t_stack *stack_a, int size)
{
	int	*ranks;
	int	*dp;
	int	*parent;
	int	*in_lis;

	ranks = ft_calloc(size, sizeof(int));
	parent = ft_calloc(size, sizeof(int));
	if (!ranks || !parent)
		return (NULL);
	fill_ranks(ranks, stack_a, size);
	dp = compute_dp(ranks, parent, size);
	in_lis = mark_lis(dp, parent, ranks, size);
	free(ranks);
	free(dp);
	free(parent);
	return (in_lis);
}

void	lis_sort(t_stack **stack_a, t_ops *ops)
{
	t_stack	*stack_b;
	int		*in_lis;

	stack_b = NULL;
	in_lis = build_in_lis(*stack_a, ft_stack_size(*stack_a));
	push_non_lis(stack_a, &stack_b, in_lis, ops);
	free(in_lis);
	while (stack_b)
		insert_element(stack_a, &stack_b, find_best(stack_a, &stack_b), ops);
	while ((*stack_a)->rank != 0)
		apply_rotate(stack_a, ops);
}
