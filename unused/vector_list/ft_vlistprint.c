/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlistprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:02:46 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:47:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_list.h"
#include "libft.h"

void	ft_vlistprint(t_vlist *list)
{
	size_t	i;

	if (!list || list->size == 0)
	{
		ft_printf("List is empty.\n");
		return ;
	}
	ft_printf("Vector List (size: %u, capacity: %u):\n",
		list->size, list->capacity);
	i = 0;
	while (i < list->size)
		ft_printf("%d ", list->array[i++]);
	ft_printf("\n");
}
