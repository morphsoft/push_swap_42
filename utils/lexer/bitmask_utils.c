/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:52:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:55:01 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmask_internal.h"

int	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == ',' || c == ';' || c == '|');
}

int	is_word_end(char c)
{
	return (c == '\0' || is_separator(c));
}

int	match_option(const char *s, const char *name)
{
	int	i;

	i = 0;
	while (name[i] && s[i] == name[i])
		i++;
	return (name[i] == '\0' && is_word_end(s[i]));
}

int	skip_token(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && !is_separator(s[i]))
		i++;
	return (i);
}
