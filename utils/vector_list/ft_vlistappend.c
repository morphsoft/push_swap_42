/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlistappend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 01:59:15 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:47:58 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_list.h"

void    ft_vlistappend(t_vlist *list, int value)
{
    if (list->size >= list->capacity)
        ft_vlistresize(list, list->capacity * 2);
    list->array[list->size] = value;
    list->size++;
}