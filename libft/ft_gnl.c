/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedr <joaopedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:54:08 by joaopedr          #+#    #+#             */
/*   Updated: 2026/06/15 21:49:28 by joaopedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buffer	*ft_create_buffer(int fd, t_buffer *buffer_list)
{
	t_buffer	*new_buffer;

	new_buffer = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new_buffer)
		return (NULL);
	new_buffer->fd = fd;
	new_buffer->content = NULL;
	new_buffer->next = buffer_list;
	return (new_buffer);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*new_buffer;
	char	*temp_buffer;
	ssize_t	bytes_read;

	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (buffer);
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp_buffer);
			break ;
		}
		temp_buffer[bytes_read] = '\0';
		new_buffer = ft_strjoin(buffer, temp_buffer);
		free(temp_buffer);
		free(buffer);
		buffer = new_buffer;
	}
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_update_buffer(char *buffer)
{
	size_t	j;
	size_t	i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(ft_strlen(buffer) - i);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buffer[i + 1 + j])
	{
		new_buffer[j] = buffer[i + 1 + j];
		j++;
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*ft_gnl(int fd)
{
	static t_buffer	*buffer_list;
	t_buffer		*current;
	char			*line;

	if (fd == -1 && buffer_list)
		ft_clear_gnl_buffer(&buffer_list);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = buffer_list;
	while (current && current->fd != fd)
		current = current->next;
	if (!current)
	{
		current = ft_create_buffer(fd, buffer_list);
		if (!current)
			return (NULL);
		buffer_list = current;
	}
	current->content = ft_read_file(fd, current->content);
	if (!current->content)
		return (NULL);
	line = ft_extract_line(current->content);
	current->content = ft_update_buffer(current->content);
	return (line);
}
