/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:42:07 by joaopedr          #+#    #+#             */
/*   Updated: 2026/05/26 23:05:33 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *arg1, const void *arg2, size_t count)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)arg1;
	ptr2 = (unsigned char *)arg2;
	i = 0;
	while (i < count)
	{
		if (ptr1[i] != ptr2[i])
		{
			return ((int)(ptr1[i] - ptr2[i]));
		}
		i++;
	}
	return (0);
}
