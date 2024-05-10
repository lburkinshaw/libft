/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:54:22 by lburkins          #+#    #+#             */
/*   Updated: 2024/01/31 16:06:34 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		gnl_free(&stash);
		return (NULL);
	}
	stash = read_file(fd, stash);
	if (malloc_check(&stash, &stash) > 0)
		return (NULL);
	line = extract_line(stash);
	if (malloc_check(&line, &stash) > 0)
		return (NULL);
	stash = trim_stash(stash, line);
	return (line);
}

char	*read_file(int fd, char *stash)
{
	char	*buff;
	int		char_read;

	char_read = 1;
	while (check_newline(stash) == 0 && char_read > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (malloc_check(&buff, &stash) > 0)
			return (NULL);
		char_read = read(fd, buff, BUFFER_SIZE);
		if ((!stash && char_read == 0) || char_read == -1)
		{
			gnl_free(&stash);
			gnl_free(&buff);
			return (NULL);
		}
		buff[char_read] = '\0';
		stash = gnl_strjoin(stash, buff);
		gnl_free(&buff);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*trim_stash(char *stash, char *line)
{
	char	*trimmed;
	int		i;
	int		j;

	i = gnl_strlen(line);
	if (stash[i] == '\0')
	{
		gnl_free(&stash);
		return (NULL);
	}
	j = gnl_strlen(stash + i);
	trimmed = malloc(sizeof(char) * (j + 1));
	if (malloc_check(&trimmed, &stash) > 0)
		return (NULL);
	j = 0;
	while (stash[i])
		trimmed[j++] = stash[i++];
	trimmed[j] = '\0';
	gnl_free(&stash);
	return (trimmed);
}
