/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:58:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/08/01 15:07:31 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef enum e_limits {
	UINT_MAX = 4294967295,
	INT_MAX = 2147483647,
	INT_MIN = -2147483648,
}	t_limits;

typedef enum e_operation_types {
	SWAP_A,
	SWAP_B,
	SWAP_BOTH,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_BOTH,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_BOTH,
	OP_TYPE_COUNT
}	t_operation_type;

typedef struct s_stack
{
	int				value;
	unsigned int	rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*create_stack(int value);
void	normalize_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	ft_push(t_stack **stack, int value, t_operation_type type);
int		ft_pop(t_stack **stack, int *value);

t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_stack_peek(t_stack *stack, int *value);
void	ft_stack_append(t_stack **stack, int value);
int		ft_stack_contains(t_stack *stack, int value);
int		ft_stack_min(t_stack *stack, int *min_value);
int		ft_stack_max(t_stack *stack, int *max_value);

void	ft_swap(t_stack **stack, t_operation_type type);
void	ft_rotate(t_stack **stack, t_operation_type type);
void	ft_reverse_rotate(t_stack **stack, t_operation_type type);
int		ft_is_sorted(t_stack *stack);

#endif
