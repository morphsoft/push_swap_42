/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:40:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/07/20 11:40:00 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	checker_init(t_stack **a, char **argv)
{
	unsigned char	flags;

	if (input_check(&argv, &flags))
		return (0);
	if (!allocate_initial_stack(a, argv))
		return (0);
	return (1);
}

static void	checker_exit(t_stack *a, t_stack *b, int status)
{
	free_stack(a);
	free_stack(b);
	if (status == -1)
		trigger_error(ERROR_INVALID_INPUT);
	else if (status == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		status;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!checker_init(&stack_a, argv))
		return (trigger_error(ERROR_INVALID_INPUT));
	status = checker_run(&stack_a, &stack_b);
	checker_exit(stack_a, stack_b, status);
	return (status == -1);
}
