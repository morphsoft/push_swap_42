/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaini-d <hvaini-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:55:55 by joaopedr          #+#    #+#             */
/*   Updated: 2026/07/27 20:13:02 by hvaini-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

int	trigger_error(int error_code)
{
	(void)error_code;
	ft_printerr("Error");
	return (1);
}

void	ft_printerr(const char *message)
{
	if (message)
		ft_putendl_fd((char *)message, 2);
}
