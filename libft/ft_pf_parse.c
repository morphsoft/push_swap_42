/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pf_apply_flag(t_fmt *fmt, char c)
{
	if (c == '-')
		fmt->minus = 1;
	else if (c == '0')
		fmt->zero = 1;
	else if (c == '#')
		fmt->hash = 1;
	else if (c == '+')
		fmt->plus = 1;
	else if (c == ' ')
		fmt->space = 1;
}

static void	pf_parse_flags_width(const char **s, t_fmt *fmt)
{
	while (**s == '-' || **s == '0' || **s == '#' || **s == ' ' || **s == '+')
	{
		pf_apply_flag(fmt, **s);
		(*s)++;
	}
	while (**s >= '0' && **s <= '9')
	{
		fmt->width = (fmt->width * 10) + (**s - '0');
		(*s)++;
	}
}

void	pf_init_fmt(t_fmt *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->hash = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->has_precision = 0;
	fmt->conv = '\0';
}

static void	pf_parse_precision(const char **s, t_fmt *fmt)
{
	if (**s != '.')
		return ;
	fmt->has_precision = 1;
	(*s)++;
	while (**s >= '0' && **s <= '9')
	{
		fmt->precision = (fmt->precision * 10) + (**s - '0');
		(*s)++;
	}
}

void	pf_parse(const char **format, t_fmt *fmt)
{
	pf_parse_flags_width(format, fmt);
	pf_parse_precision(format, fmt);
	fmt->conv = **format;
	if (**format)
		(*format)++;
}
