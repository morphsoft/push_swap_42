/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 21:48:04 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/15 22:28:36 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	float			disorder;
	unsigned char	flags;

	if (input_check(&argv, &flags) || !allocate_initial_stack(stack_a, argv))
		return (NULL);

	//Checar as flags com bitwise (000010101010 (varias flags))
	disorder = compute_disorder(stack_a);
	if (has_low_flag(flags) || disorder < 0.2)
		simple_sort(&stack_a, flags);
	else if (has_medium_flag(flags) || disorder < 0.5)
		medium_sort(&stack_a, flags);
	else if (has_high_flag(flags) || disorder >= 0.5)
		complex_sort(&stack_a, flags);
}
