/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:38:11 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:42:36 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
    int	count;

    count = 0;
    if (!str)
        return (ft_putstr("(null)"));
    while (*str)
        count += ft_putchar(*str++);
    return (count);
}