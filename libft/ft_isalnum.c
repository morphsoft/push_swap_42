/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:47:24 by joaopedr          #+#    #+#             */
/*   Updated: 2026/05/26 23:05:33 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= 'A' && argument <= 'Z') || (argument >= 'a'
			&& argument <= 'z') || (argument >= '0' && argument <= '9'))
	{
		return (1);
	}
	return (0);
}
