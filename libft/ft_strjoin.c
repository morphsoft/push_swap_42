/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:49:46 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:29:43 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	char	*ptr;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		s1 = "";
	joined_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined_string == NULL)
		return (NULL);
	ptr = joined_string;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (joined_string);
}
