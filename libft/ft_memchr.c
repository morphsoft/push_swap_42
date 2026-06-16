/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:24:27 by joaopedr          #+#    #+#             */
/*   Updated: 2026/05/26 23:05:33 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	val;

	ptr = (unsigned char *)pointer;
	val = (unsigned char)value;
	i = 0;
	while (i < count)
	{
		if (ptr[i] == val)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
