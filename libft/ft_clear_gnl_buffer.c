/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_gnl_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 21:47:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:47:21 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_gnl_buffer(t_buffer **buffer_list)
{
    t_buffer	*current;
    t_buffer	*temp;

    current = *buffer_list;
    while (current)
    {
        temp = current->next;
        free(current->content);
        free(current);
        current = temp;
    }
    *buffer_list = NULL;
}