/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:20:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	pf_repeat(char c, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += ft_putchar(c);
	return (count);
}

int	pf_putnstr(const char *s, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += ft_putchar(*s++);
	return (count);
}

int	pf_u64_to_base(unsigned long long n, const char *base, char *buf)
{
	char	rev[65];
	int		base_len;
	int		i;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n == 0)
		return (buf[0] = '0', 1);
	i = 0;
	while (n > 0)
	{
		rev[i++] = base[n % base_len];
		n /= base_len;
	}
	base_len = i;
	while (i-- > 0)
		*buf++ = rev[i];
	return (base_len);
}
