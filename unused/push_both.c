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

void	ft_push_both(t_stack **a, t_stack **b, int *values, t_operation_type t)
{
	ft_push(a, values[0], t);
	ft_push(b, values[1], t);
}
