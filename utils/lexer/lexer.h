/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:58:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/23 14:03:11 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_flag_mask {
	FLAG_NONE = 0,
	FLAG_SIMPLE = 1 << 0,
	FLAG_MEDIUM = 1 << 1,
	FLAG_COMPLEX = 1 << 2,
	FLAG_ADAPTIVE = 1 << 3,
	FLAG_BENCHMARK = 1 << 4,
}	t_flag_mask;

typedef enum e_algorithm_type {
	ALGO_SIMPLE,
	ALGO_MEDIUM,
	ALGO_COMPLEX
}	t_algorithm_type;

typedef struct s_flags
{
	unsigned char	simple;
	unsigned char	medium;
	unsigned char	complex;
	unsigned char	adaptive;
	unsigned char	benchmark;
}	t_flags;

int		parse_flags_mask(const char *flags_str, unsigned char *flags);
int		has_simple_flag(unsigned char flags);
int		has_medium_flag(unsigned char flags);
int		has_complex_flag(unsigned char flags);
int		has_adaptive_flag(unsigned char flags);
int		has_benchmark_flag(unsigned char flags);
int		build_flags_state(unsigned char flags, t_flags *state);
t_algorithm_type	resolve_algorithm(const t_flags *state, float disorder);

#endif
