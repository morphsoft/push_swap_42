/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:52:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:54:55 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	has_simple_flag(unsigned char flags)
{
	return ((flags & FLAG_SIMPLE) != 0);
}

int	has_medium_flag(unsigned char flags)
{
	return ((flags & FLAG_MEDIUM) != 0);
}

int	has_complex_flag(unsigned char flags)
{
	return ((flags & FLAG_COMPLEX) != 0);
}

int	has_adaptive_flag(unsigned char flags)
{
	return ((flags & FLAG_ADAPTIVE) != 0);
}

int	has_benchmark_flag(unsigned char flags)
{
	return ((flags & FLAG_BENCHMARK) != 0);
}
