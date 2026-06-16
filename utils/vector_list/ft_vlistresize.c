/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlistresize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:00:29 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:47:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_list.h"

void    ft_vlistresize(t_vlist *list, size_t new_capacity)
{
    int	*new_array;
    size_t	i;

    new_array = (int *)malloc(sizeof(int) * new_capacity);
    if (!new_array)
        return ;
    i = 0;
    while (i < list->size)
    {
        new_array[i] = list->array[i];
        i++;
    }
    free(list->array);
    list->array = new_array;
    list->capacity = new_capacity;
}