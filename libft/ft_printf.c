/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:31:12 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	t_fmt	fmt;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
			count += ft_putchar(*format++);
		else
		{
			format++;
			pf_init_fmt(&fmt);
			pf_parse(&format, &fmt);
			count += pf_dispatch(&fmt, &args);
		}
	}
	va_end(args);
	return (count);
}