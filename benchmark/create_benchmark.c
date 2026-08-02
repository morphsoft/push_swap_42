/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_benchmark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:20:26 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:04:22 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	sum_ops(int *op_count)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < OP_TYPE_COUNT)
		total += op_count[i++];
	return (total);
}

static char	*strategy_name(unsigned char flags)
{
	if (flags & FLAG_SIMPLE)
		return ("Simple");
	if (flags & FLAG_MEDIUM)
		return ("Medium");
	if (flags & FLAG_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static void	put_disorder(double dis)
{
	int	hundredths;

	hundredths = (int)(dis * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(hundredths / 100, 2);
	ft_putchar_fd('.', 2);
	if (hundredths % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(hundredths % 100, 2);
	ft_putendl_fd("%", 2);
}

static void	put_counts(int *op_count)
{
	const char	*names[OP_TYPE_COUNT] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	ft_putstr_fd("[bench] ", 2);
	i = 0;
	while (i < OP_TYPE_COUNT)
	{
		ft_putstr_fd((char *)names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(op_count[i], 2);
		if (++i < OP_TYPE_COUNT)
			ft_putstr_fd("  ", 2);
	}
	ft_putchar_fd('\n', 2);
}

void	create_benchmark(unsigned char flags, char *class, int *op, double dis)
{
	put_disorder(dis);
	ft_putstr_fd("[bench] strategy:   ", 2);
	ft_putstr_fd(strategy_name(flags), 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd(class, 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(sum_ops(op), 2);
	ft_putchar_fd('\n', 2);
	put_counts(op);
}
