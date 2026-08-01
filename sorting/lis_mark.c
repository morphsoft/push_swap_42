/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_mark.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:52:49 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:04:56 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	best_end(int *chain_len, int size)
{
	int	max_len;
	int	idx;
	int	i;

	max_len = 0;
	idx = 0;
	i = 0;
	while (i < size)
	{
		if (chain_len[i] > max_len)
		{
			max_len = chain_len[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int	*mark_lis(int *chain_len, int *prev_pos, int *ranks, int size)
{
	int	*in_lis;
	int	idx;

	in_lis = ft_calloc(size, sizeof(int));
	if (!in_lis)
		return (NULL);
	idx = best_end(chain_len, size);
	while (idx != -1)
	{
		in_lis[ranks[idx]] = 1;
		idx = prev_pos[idx];
	}
	return (in_lis);
}
