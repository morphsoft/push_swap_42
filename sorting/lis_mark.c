/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_mark.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:52:49 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:55:51 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

/* index where the longest increasing subsequence ends */
static int	best_end(int *dp, int size)
{
	int	max_len;
	int	idx;
	int	i;

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
	return (idx);
}

/* flag every rank belonging to the LIS, walking the parent chain back */
int	*mark_lis(int *dp, int *parent, int *ranks, int size)
{
	int	*in_lis;
	int	idx;

	in_lis = ft_calloc(size, sizeof(int));
	if (!in_lis)
		return (NULL);
	idx = best_end(dp, size);
	while (idx != -1)
	{
		in_lis[ranks[idx]] = 1;
		idx = parent[idx];
	}
	return (in_lis);
}
