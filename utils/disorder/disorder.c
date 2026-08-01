/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:52:49 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:07:05 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_after(t_stack *a, int start, int size)
{
	t_stack	*b;
	int		mistakes;
	int		i;

	b = a->next;
	mistakes = 0;
	i = start + 1;
	while (i < size)
	{
		if (a->value > b->value)
			mistakes++;
		b = b->next;
		i++;
	}
	return (mistakes);
}

float	compute_disorder(t_stack *stack_a)
{
	t_stack	*a;
	int		size;
	int		mistakes;
	int		i;

	size = ft_stack_size(stack_a);
	if (size < 2)
		return (0.0f);
	mistakes = 0;
	a = stack_a;
	i = 0;
	while (i < size - 1)
	{
		mistakes += count_after(a, i, size);
		a = a->next;
		i++;
	}
	return ((float)mistakes / (size * (size - 1) / 2));
}
