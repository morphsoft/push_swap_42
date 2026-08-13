/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 00:00:00 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:48:30 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	log_grow(t_log *log, size_t need)
{
	char	*buf;
	size_t	cap;

	cap = log->cap;
	if (cap < LOG_MIN_CAP)
		cap = LOG_MIN_CAP;
	while (cap < need)
		cap *= 2;
	buf = malloc(cap);
	if (!buf)
		return (0);
	if (log->buf)
		ft_memcpy(buf, log->buf, log->len);
	free(log->buf);
	log->buf = buf;
	log->cap = cap;
	return (1);
}

void	log_append(t_log *log, const char *op)
{
	size_t	len;

	if (log->oom)
		return ;
	len = ft_strlen(op);
	if (log->len + len > log->cap && !log_grow(log, log->len + len))
	{
		log->oom = 1;
		return ;
	}
	ft_memcpy(log->buf + log->len, op, len);
	log->len += len;
}

void	run_sort(t_stack **stack_a, t_sort_run *run)
{
	int		op_count[OP_TYPE_COUNT];
	t_log	log;
	t_ops	ops;

	ft_bzero(op_count, sizeof(op_count));
	ft_bzero(&log, sizeof(log));
	ops.count = op_count;
	ops.log = &log;
	run->algo(stack_a, &ops);
	if (log.oom)
		trigger_error(ERROR_MEMORY_ALLOCATION);
	else if (run->flags & FLAG_BENCHMARK)
		create_benchmark(run->flags, run->label, op_count, run->disorder);
	else if (log.buf)
		write(1, log.buf, log.len);
	free(log.buf);
}
