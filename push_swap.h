/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:44:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/19 19:42:28 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "utils/push_swap_utils.h"
# include "sorting_operations/sorting_operations.h"
# include "utils/error_handeling/error_handeling.h"


int		input_check(char ***argv, unsigned char *flags);
int		allocate_initial_stack(t_stack **stack_a, char **argv);
float	compute_disorder(t_stack *stack_a);
void	simple_sort(t_stack **stack_a, unsigned char flags, double disorder);
void	medium_sort(t_stack **stack_a, unsigned char flags, double disorder);
void	complex_sort(t_stack **stack_a, unsigned char flags, double disorder);
void	super_small_sort(t_stack **stack_a, unsigned char flags, double disorder);

#endif
