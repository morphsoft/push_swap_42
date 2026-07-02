/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 by hvaini-d                  #+#    #+#             */
/*   Updated: 2026/06/23 by hvaini-d                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	medium_sort(t_stack **stack_a, unsigned char flags, double disorder)
{
	int		op_count[11];
	char	*log;
	t_ops	ops;

	log = ft_strdup("");
	ft_bzero(op_count, sizeof(op_count));
	ops.count = op_count;
	ops.log = &log;
	lis_sort(stack_a, &ops);
	if (flags & FLAG_BENCHMARK)
		create_benchmark("medium / O(n sqrt n)", op_count, log, disorder);
	else
		ft_printf("%s\n", log);
	free(log);
}
