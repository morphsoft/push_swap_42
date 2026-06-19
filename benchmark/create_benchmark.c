/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_benchmark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:20:26 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/19 19:33:01 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap_utils.h"

void	create_benchmark(char **name, int **op_count, char **ops, double dis)
{
	ft_printf("[bench] disorder:   %d\n", dis);
	ft_printf("[bench] strategy:   %s\n", name);
	ft_printf("[bench] total_ops:  %i\n", sum_ops(op_count));
	ft_printf("[bench] sa: %i  sb: %i  ss: %i  pa: %i  pb: %i\n",
		op_count[SWAP_A], op_count[SWAP_B],
		op_count[SWAP_BOTH], op_count[PUSH_A],
		op_count[PUSH_B]);
	ft_printf("[bench] ra: %i  rb: %i  rr: %i  rra: %i  rrb: %i  rrr: %i\n",
		op_count[ROTATE_A], op_count[ROTATE_B],
		op_count[ROTATE_BOTH], op_count[REVERSE_ROTATE_A],
		op_count[REVERSE_ROTATE_B], op_count[REVERSE_ROTATE_BOTH]);
}
