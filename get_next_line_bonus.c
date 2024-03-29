/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:00:09 by dgross            #+#    #+#             */
/*   Updated: 2022/05/19 12:12:31 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" // ft_strchr ft_strjoin ft_strlen 

#include <stddef.h> // NULL size_t
#include <stdlib.h> // malloc free
#include <unistd.h> // read

char	*read_line(int fd, char *string)
{
	char		*buffer;
	int			bytes_read;

	bytes_read = 1;
	buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(string, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free (buffer);
	return (string);
}

char	*malloc_line(char *string)
{
	int		i;
	char	*pointer;

	if (!*string)
		return (NULL);
	i = 0;
	if (!string)
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	pointer = malloc (sizeof(char) * (i + 2));
	if (!pointer)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		pointer[i] = string[i];
		i++;
	}
	if (string[i] && string[i] == '\n')
		pointer[i++] = '\n';
	pointer[i] = '\0';
	return (pointer);
}

char	*keep_line(char *string)
{
	int		i;
	int		j;
	char	*pointer;
	int		str_len;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	str_len = ft_strlen(string);
	pointer = malloc(sizeof(char) * (str_len - i + 1));
	if (!pointer)
		return (NULL);
	i++;
	j = 0;
	while (string[i])
		pointer[j++] = string[i++];
	pointer[j] = '\0';
	free(string);
	return (pointer);
}

char	*get_next_line(int fd)
{
	static char	*string[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	string[fd] = read_line(fd, string[fd]);
	if (!string[fd])
		return (NULL);
	line = malloc_line(string[fd]);
	string[fd] = keep_line(string[fd]);
	return (line);
}
