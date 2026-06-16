/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_sign(long value, t_fmt *fmt)
{
	if (value < 0)
		return ('-');
	if (fmt->plus)
		return ('+');
	if (fmt->space)
		return (' ');
	return (0);
}

static int	pf_prefix(t_fmt *fmt, char conv, unsigned long long value)
{
	if (!fmt->hash || value == 0)
		return (0);
	if (conv == 'x' || conv == 'X')
		return (2);
	return (0);
}

static int	pf_write_num(char *digits, t_nfmt *n, t_fmt *fmt, char conv)
{
	int	count;

	count = 0;
	if (!fmt->minus && (!fmt->zero || fmt->has_precision))
		count += pf_repeat(' ', n->pad);
	if (n->sign)
		count += ft_putchar(n->sign);
	if (n->prefix)
	{
		if (conv == 'X')
			count += pf_putnstr("0X", 2);
		else
			count += pf_putnstr("0x", 2);
	}
	if (!fmt->minus && fmt->zero && !fmt->has_precision)
		count += pf_repeat('0', n->pad);
	count += pf_repeat('0', n->zpad);
	count += pf_putnstr(digits, n->len);
	if (fmt->minus)
		count += pf_repeat(' ', n->pad);
	return (count);
}

int	pf_print_signed(long value, t_fmt *fmt)
{
	char			digits[32];
	t_nfmt		n;
	unsigned long long	abs_v;

	if (value < 0)
		abs_v = (unsigned long long)(-value);
	else
		abs_v = (unsigned long long)value;
	n.len = pf_u64_to_base(abs_v, "0123456789", digits);
	if (fmt->has_precision && fmt->precision == 0 && abs_v == 0)
		n.len = 0;
	n.sign = pf_sign(value, fmt);
	if (fmt->has_precision)
		n.zpad = pf_max(0, fmt->precision - n.len);
	else
		n.zpad = 0;
	n.prefix = 0;
	n.pad = pf_max(0, fmt->width - (n.len + n.zpad + (n.sign != 0)));
	return (pf_write_num(digits, &n, fmt, 'd'));
}

int	pf_print_unsigned(unsigned long long value, t_fmt *fmt, char conv)
{
	char		*base;
	char		digits[65];
	t_nfmt		n;

	if (conv == 'u')
		base = "0123456789";
	else
		base = "0123456789abcdef";
	if (conv == 'X')
		base = "0123456789ABCDEF";
	n.len = pf_u64_to_base(value, base, digits);
	if (fmt->has_precision && fmt->precision == 0 && value == 0)
		n.len = 0;
	n.sign = 0;
	n.prefix = pf_prefix(fmt, conv, value);
	if (fmt->has_precision)
		n.zpad = pf_max(0, fmt->precision - n.len);
	else
		n.zpad = 0;
	n.pad = pf_max(0, fmt->width - (n.len + n.zpad + n.prefix));
	return (pf_write_num(digits, &n, fmt, conv));
}
