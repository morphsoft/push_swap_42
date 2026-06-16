/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:39:50 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int number)
{
    int	count;

    count = 0;
    if (number == -2147483648)
        return (ft_putstr("-2147483648"));
    if (number < 0)
    {
        count += ft_putchar('-');
        number = -number;
    }
    if (number >= 10)
        count += ft_putnbr(number / 10);
    count += ft_putchar((number % 10) + '0');
    return (count);
}