/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlist_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:08:51 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:47:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_list.h"

void	vlist_iter(t_vlist *list, void (*func)(int *))
{
	size_t	i;

	if (!list || !func)
		return ;
	i = 0;
	while (i < list->size)
		func(&list->array[i++]);
}
