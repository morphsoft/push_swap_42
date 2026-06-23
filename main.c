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

int	main(int argc, char **argv)
{
	t_stack				*stack_a;
	float				disorder;
	unsigned char		flags;
	t_flags				flag_state;
	t_algorithm_type	algorithm;

	if (input_check(&argv, &flags) || !allocate_initial_stack(stack_a, argv))
		return (NULL);
	if (!build_flags_state(flags, &flag_state))
		return (1);

	disorder = compute_disorder(stack_a);
	algorithm = resolve_algorithm(&flag_state, disorder);
	if (algorithm == ALGO_SIMPLE)
		simple_sort(&stack_a, flags, disorder);
	else if (algorithm == ALGO_MEDIUM)
		medium_sort(&stack_a, flags, disorder);
	else
		complex_sort(&stack_a, flags, disorder);
}
