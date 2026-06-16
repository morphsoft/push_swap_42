/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dispatch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_dispatch(t_fmt *fmt, va_list *args)
{
	if (fmt->conv == 'c')
		return (pf_print_char((char)va_arg(*args, int), fmt));
	if (fmt->conv == 's')
		return (pf_print_string(va_arg(*args, char *), fmt));
	if (fmt->conv == 'p')
		return (pf_print_pointer(va_arg(*args, void *), fmt));
	if (fmt->conv == 'd' || fmt->conv == 'i')
		return (pf_print_signed((long)va_arg(*args, int), fmt));
	if (fmt->conv == 'u' || fmt->conv == 'x' || fmt->conv == 'X')
		return (pf_print_unsigned((unsigned long long)va_arg(*args, unsigned int),
				fmt, fmt->conv));
	if (fmt->conv == '%')
		return (pf_print_char('%', fmt));
	if (fmt->conv)
		return (ft_putchar(fmt->conv));
	return (0);
}
