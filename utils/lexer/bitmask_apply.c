/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:52:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:54:54 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmask_internal.h"

int	set_selector(unsigned char *flags, unsigned char selector)
{
	if (*flags & (FLAG_SIMPLE | FLAG_MEDIUM | FLAG_COMPLEX | FLAG_ADAPTIVE))
		return (0);
	*flags |= selector;
	return (1);
}

int	apply_option(unsigned char *flags, const char *s, int *len)
{
	if (match_option(s, "--simple"))
		return (*len = 8, set_selector(flags, FLAG_SIMPLE));
	if (match_option(s, "--medium"))
		return (*len = 8, set_selector(flags, FLAG_MEDIUM));
	if (match_option(s, "--complex"))
		return (*len = 9, set_selector(flags, FLAG_COMPLEX));
	if (match_option(s, "--adaptive"))
		return (*len = 10, set_selector(flags, FLAG_ADAPTIVE));
	if (!match_option(s, "--bench"))
		return (0);
	*len = 7;
	*flags |= FLAG_BENCHMARK;
	return (1);
}

void	apply_default_selector(unsigned char *flags)
{
	if (!(*flags & (FLAG_SIMPLE | FLAG_MEDIUM | FLAG_COMPLEX | FLAG_ADAPTIVE)))
		*flags |= FLAG_ADAPTIVE;
}

int	parse_options(const char *flags_str, unsigned char *flags)
{
	int	i;
	int	len;

	i = 0;
	while (flags_str[i])
	{
		while (flags_str[i] && is_separator(flags_str[i]))
			i++;
		if (!flags_str[i])
			break ;
		if (!apply_option(flags, flags_str + i, &len))
			return (0);
		i += len;
		i += skip_token(flags_str + i);
	}
	return (1);
}
