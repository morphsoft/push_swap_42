/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:58:00 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:46:30 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIST_H
# define VECTOR_LIST_H

# include <stdlib.h>

typedef struct vector_list
{
	int		*array;
	size_t	size;
	size_t	capacity;
}	t_vlist;

t_vlist	*create_vlist(size_t initial_capacity);
void	free_vlist(t_vlist *list);
void	ft_vlistappend(t_vlist *list, int value);
void	ft_vlistpop(t_vlist *list);
void	ft_vlistpush(t_vlist *list, int value);
void	ft_vlistresize(t_vlist *list, size_t new_capacity);
void	ft_vlistprint(t_vlist *list);
void	vlist_iter(t_vlist *list, void (*func)(int *));

#endif
