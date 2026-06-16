/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:14:06 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:59:05 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_operations.h"

void	ft_push(t_stack **stack, int value, t_operation_type type)
{
    t_stack	*new_node;
    t_stack	*last;

    (void)type;

    new_node = create_stack(value);
    if (!new_node)
        return ;
    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
    last = (*stack)->prev;
    new_node->next = *stack;
    new_node->prev = last;
    last->next = new_node;
    (*stack)->prev = new_node;
    *stack = new_node;
}