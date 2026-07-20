/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:40:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/07/20 11:40:00 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker_run(t_stack **a, t_stack **b)
{
	char	*line;

	line = ft_gnl(0);
	while (line)
	{
		if (!execute_op(a, b, line))
		{
			free(line);
			ft_gnl(-1);
			return (-1);
		}
		free(line);
		line = ft_gnl(0);
	}
	if (ft_is_sorted(*a) && !*b)
		return (0);
	return (1);
}
