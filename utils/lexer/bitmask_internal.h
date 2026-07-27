/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:52:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:54:57 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMASK_INTERNAL_H
# define BITMASK_INTERNAL_H

# include "lexer.h"

int		is_separator(char c);
int		is_word_end(char c);
int		match_option(const char *s, const char *name);
int		skip_token(const char *s);
int		set_selector(unsigned char *flags, unsigned char selector);
int		apply_option(unsigned char *flags, const char *s, int *len);
void	apply_default_selector(unsigned char *flags);
int		parse_options(const char *flags_str, unsigned char *flags);

#endif
