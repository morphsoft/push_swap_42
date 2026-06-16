/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:54:38 by joaopedr          #+#    #+#             */
/*   Updated: 2026/05/28 01:31:04 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_make_sep(char *sep, char c)
{
	sep[0] = c;
	sep[1] = '\0';
}

static size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i] && !ft_strchr(reject, s[i]))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	sep[2];
	char	**result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ft_make_sep(sep, c);
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			result[j++] = ft_substr(s, i, ft_strcspn(s + i, sep));
		while (s[i] && s[i] != c)
			i++;
	}
	result[j] = NULL;
	return (result);
}
