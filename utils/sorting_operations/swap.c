/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:14:06 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:59:10 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_operations.h"

void	ft_swap(t_stack **stack, t_operation_type type)
{
	(void)type;
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	(*stack)->value ^= (*stack)->next->value;
	(*stack)->next->value ^= (*stack)->value;
	(*stack)->value ^= (*stack)->next->value;
}
