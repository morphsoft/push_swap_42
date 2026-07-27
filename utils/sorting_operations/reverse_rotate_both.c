/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:28:35 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:54:46 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting_operations.h"

void	ft_reverse_rotate_both(t_stack **a, t_stack **b, t_operation_type type)
{
	ft_reverse_rotate(a, type);
	ft_reverse_rotate(b, type);
}
