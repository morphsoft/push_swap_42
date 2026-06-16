/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_cs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_print_char(char c, t_fmt *fmt)
{
	int	pad;
	int	count;

	pad = pf_max(0, fmt->width - 1);
	count = 0;
	if (!fmt->minus)
	{
		if (fmt->zero)
			count += pf_repeat('0', pad);
		else
			count += pf_repeat(' ', pad);
	}
	count += ft_putchar(c);
	if (fmt->minus)
		count += pf_repeat(' ', pad);
	return (count);
}

int	pf_print_string(char *s, t_fmt *fmt)
{
	int	len;
	int	out_len;
	int	count;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	out_len = len;
	if (fmt->has_precision && fmt->precision < out_len)
		out_len = fmt->precision;
	count = 0;
	if (!fmt->minus)
		count += pf_repeat(' ', pf_max(0, fmt->width - out_len));
	count += pf_putnstr(s, out_len);
	if (fmt->minus)
		count += pf_repeat(' ', pf_max(0, fmt->width - out_len));
	return (count);
}
