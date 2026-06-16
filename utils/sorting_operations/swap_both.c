/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:29:56 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:54:50 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_operations.h"

void ft_swap_both(t_stack **stack_a, t_stack **stack_b, t_operation_type type)
{
    ft_swap(stack_a, type);
    ft_swap(stack_b, type);
}