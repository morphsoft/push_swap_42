/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlistpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:12:37 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:47:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_list.h"

void    ft_vlistpush(t_vlist *list, int value)
{
    if (list->size >= list->capacity)
        ft_vlistresize(list, list->capacity * 2);
    size_t  i;

    i = list->size;
    while (i > 0)
    {
        list->array[i] = list->array[i - 1];
        i--;
    }
    list->array[0] = value;
    list->size++;
}