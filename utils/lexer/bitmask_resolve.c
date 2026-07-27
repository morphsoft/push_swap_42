/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask_resolve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:52:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:55:00 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	build_flags_state(unsigned char flags, t_flags *state)
{
	if (!state)
		return (0);
	state->simple = has_simple_flag(flags);
	state->medium = has_medium_flag(flags);
	state->complex = has_complex_flag(flags);
	state->adaptive = has_adaptive_flag(flags);
	state->benchmark = has_benchmark_flag(flags);
	return (1);
}

t_algo_type	resolve_algorithm(const t_flags *state, float disorder)
{
	if (!state)
		return (ALGO_COMPLEX);
	if (state->simple)
		return (ALGO_SIMPLE);
	if (state->medium)
		return (ALGO_MEDIUM);
	if (state->complex)
		return (ALGO_COMPLEX);
	if (disorder < 0.2f)
		return (ALGO_SIMPLE);
	if (disorder < 0.5f)
		return (ALGO_MEDIUM);
	return (ALGO_COMPLEX);
}
