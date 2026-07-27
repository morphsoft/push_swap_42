/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:52:49 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:55:51 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

/* cheapest way to bring `pos` to the top: +1 = rotate, -1 = reverse rotate */
static void	split_move(int pos, int size, int *dir, int *count)
{
	if (pos <= size / 2)
	{
		*dir = 1;
		*count = pos;
	}
	else
	{
		*dir = -1;
		*count = size - pos;
	}
}

/*
** What turn_both will actually spend: shared steps cost one rr/rrr each, so
** matching directions cost max(a, b) rather than a + b.
*/
int	move_cost(t_move *m)
{
	int	dir_a;
	int	dir_b;
	int	count_a;
	int	count_b;

	split_move(m->pos_a, m->size_a, &dir_a, &count_a);
	split_move(m->pos_b, m->size_b, &dir_b, &count_b);
	if (dir_a != dir_b)
		return (count_a + count_b);
	if (count_a > count_b)
		return (count_a);
	return (count_b);
}

static void	finish_a(t_stack **a, int dir, int count, t_ops *ops)
{
	while (count-- > 0)
	{
		if (dir == 1)
			apply_rotate(a, ops);
		else
			apply_reverse_rotate(a, ops);
	}
}

static void	finish_b(t_stack **b, int dir, int count, t_ops *ops)
{
	while (count-- > 0)
	{
		if (dir == 1)
			apply_rotate_b(b, ops);
		else
			apply_reverse_rotate_b(b, ops);
	}
}

/*
** Bring m->pos_a and m->pos_b to the top of their stacks, spending a single
** rr/rrr for every step both stacks share instead of two separate rotations.
*/
void	turn_both(t_stack **a, t_stack **b, t_move *m, t_ops *ops)
{
	int	dir_a;
	int	dir_b;
	int	left_a;
	int	left_b;

	split_move(m->pos_a, m->size_a, &dir_a, &left_a);
	split_move(m->pos_b, m->size_b, &dir_b, &left_b);
	while (dir_a == dir_b && left_a > 0 && left_b > 0)
	{
		if (dir_a == 1)
			apply_rotate_both(a, b, ops);
		else
			apply_reverse_rotate_both(a, b, ops);
		left_a--;
		left_b--;
	}
	finish_a(a, dir_a, left_a, ops);
	finish_b(b, dir_b, left_b, ops);
}
