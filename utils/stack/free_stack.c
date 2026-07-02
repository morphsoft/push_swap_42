/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:22:58 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:46:56 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void    free_stack(t_stack *stack)
{
    t_stack	*current;
    t_stack	*next;

    if (!stack)
        return ;
    current = stack->next;
    while (current != stack)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}