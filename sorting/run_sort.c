/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 00:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:06:28 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	run_sort(t_stack **stack_a, t_sort_run *run)
{
	int		op_count[OP_TYPE_COUNT];
	char	*log;
	t_ops	ops;

	log = ft_strdup("");
	if (!log)
		return ;
	ft_bzero(op_count, sizeof(op_count));
	ops.count = op_count;
	ops.log = &log;
	run->algo(stack_a, &ops);
	ft_printf("%s", log);
	if (run->flags & FLAG_BENCHMARK)
		create_benchmark(run->flags, run->label, op_count, run->disorder);
	free(log);
}
