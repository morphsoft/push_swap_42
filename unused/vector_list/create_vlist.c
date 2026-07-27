/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 01:58:31 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:46:56 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_list.h"

t_vlist	*create_vlist(size_t initial_capacity)
{
    t_vlist	*list;

    list = (t_vlist *)malloc(sizeof(t_vlist));
    if (!list)
        return (NULL);
    list->array = (int *)malloc(sizeof(int) * initial_capacity);
    if (!list->array)
    {
        free(list);
        return (NULL);
    }
    list->size = 0;
    list->capacity = initial_capacity;
    return (list);
}