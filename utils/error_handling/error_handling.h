/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:56:09 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/16 02:57:50 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "libft/libft.h"

enum	e_error_codes
{
	ERROR_NONE = 0,
	ERROR_INVALID_INPUT = 1,
	ERROR_MEMORY_ALLOCATION = 2,
	ERROR_UNKNOWN = 3
};

int		trigger_error(int error_code);
void	ft_printerr(const char *message);

#endif
