/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_print_pointer(void *ptr, t_fmt *fmt)
{
	char			digits[65];
	unsigned long	value;
	int				len;
	int				count;

	if (!ptr)
		return (pf_print_string("(nil)", fmt));
	value = (unsigned long)ptr;
	len = pf_u64_to_base(value, "0123456789abcdef", digits);
	count = 0;
	if (!fmt->minus)
	{
		if (fmt->zero)
			count += pf_repeat('0', pf_max(0, fmt->width - len - 2));
		else
			count += pf_repeat(' ', pf_max(0, fmt->width - len - 2));
	}
	count += pf_putnstr("0x", 2);
	count += pf_putnstr(digits, len);
	if (fmt->minus)
		count += pf_repeat(' ', pf_max(0, fmt->width - len - 2));
	return (count);
}
