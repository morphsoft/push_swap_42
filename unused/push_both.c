/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:29:37 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:50:18 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_operations.h"

void ft_push_both(t_stack **stack_a, t_stack **stack_b, int value_a, int value_b, t_operation_type type)
{
    ft_push(stack_a, value_a, type);
    ft_push(stack_b, value_b, type);
}