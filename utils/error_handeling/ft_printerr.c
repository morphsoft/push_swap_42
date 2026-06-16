/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:55:55 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:58:53 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handeling.h"

void	ft_printerr(const char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
}
