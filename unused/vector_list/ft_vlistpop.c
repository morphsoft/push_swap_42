/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlistpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:09:27 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:47:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_list.h"

void	ft_vlistpop(t_vlist *list)
{
	if (list && list->size > 0)
	{
		list->array[list->size--] = 0;
		if (list->size > 0 && list->size <= list->capacity / 4)
			ft_vlistresize(list, list->capacity / 2);
	}
}
