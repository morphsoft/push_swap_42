/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 21:48:04 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:29:15 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dispatch_sort(t_stack **a, unsigned char flags, t_flags *state,
		float disorder)
{
	t_algo_type	algorithm;

	algorithm = resolve_algorithm(state, disorder);
	if (algorithm == ALGO_SIMPLE && ft_stack_size(*a) <= 5)
		super_small_sort(a, flags, disorder);
	else if (algorithm == ALGO_SIMPLE)
		simple_sort(a, flags, disorder);
	else if (algorithm == ALGO_MEDIUM)
		medium_sort(a, flags, disorder);
	else
		complex_sort(a, flags, disorder);
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	unsigned char	flags;
	t_flags			flag_state;

	(void)argc;
	if (input_check(&argv, &flags) || !allocate_initial_stack(&stack_a, argv))
		return (trigger_error(ERROR_INVALID_INPUT));
	if (!build_flags_state(flags, &flag_state))
		return (trigger_error(ERROR_INVALID_INPUT));
	if (!ft_is_sorted(stack_a))
		dispatch_sort(&stack_a, flags, &flag_state, compute_disorder(stack_a));
	free_stack(stack_a);
	return (0);
}
