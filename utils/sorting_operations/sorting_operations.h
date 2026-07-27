/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 03:09:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:54:48 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_OPERATIONS_H
# define SORTING_OPERATIONS_H

# include "../utils/stack/stack.h"

void	ft_swap(t_stack **stack, t_operation_type type);
void	ft_push(t_stack **stack, int value, t_operation_type type);
void	ft_rotate(t_stack **stack, t_operation_type type);
void	ft_reverse_rotate(t_stack **stack, t_operation_type type);
void	ft_swap_both(t_stack **a, t_stack **b, t_operation_type type);
void	ft_rotate_both(t_stack **a, t_stack **b, t_operation_type type);
void	ft_reverse_rotate_both(t_stack **a, t_stack **b, t_operation_type type);

#endif
