/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmask_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:52:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:54:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmask_internal.h"

int	parse_flags_mask(const char *flags_str, unsigned char *flags)
{
	if (!flags)
		return (0);
	*flags = FLAG_NONE;
	if (!flags_str)
	{
		*flags = FLAG_ADAPTIVE;
		return (1);
	}
	if (!parse_options(flags_str, flags))
		return (0);
	apply_default_selector(flags);
	return (1);
}
