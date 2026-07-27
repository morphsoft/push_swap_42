/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:52:49 by hvaini-d          #+#    #+#             */
/*   Updated: 2026/06/23 15:55:51 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(char *arg, unsigned char *flags)
{
	int	len;

	return (apply_option(flags, arg, &len));
}

static int	is_valid_int(const char *s)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	if (!s[i])
		return (0);
	n = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		n = n * 10 + (s[i++] - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
	}
	return (1);
}

int	input_check(char ***argv, unsigned char *flags)
{
	int	i;

	*flags = FLAG_NONE;
	i = 1;
	while ((*argv)[i] && (*argv)[i][0] == '-' && (*argv)[i][1] == '-')
	{
		if (!parse_flags((*argv)[i], flags))
			return (1);
		i++;
	}
	if (!(*flags & (FLAG_SIMPLE | FLAG_MEDIUM | FLAG_COMPLEX | FLAG_ADAPTIVE)))
		*flags |= FLAG_ADAPTIVE;
	*argv += (i - 1);
	i = 1;
	while ((*argv)[i])
	{
		if (!is_valid_int((*argv)[i]))
			return (1);
		i++;
	}
	return (0);
}

int	allocate_initial_stack(t_stack **stack_a, char **argv)
{
	int	i;
	int	value;

	*stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (ft_stack_contains(*stack_a, value))
			return (free_stack(*stack_a), *stack_a = NULL, 0);
		ft_stack_append(stack_a, value);
		i++;
	}
	normalize_stack(*stack_a);
	return (1);
}
