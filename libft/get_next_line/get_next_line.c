/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:09:10 by joyim             #+#    #+#             */
/*   Updated: 2024/07/30 16:52:36 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

static char	*function(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line <= -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	int		count;
	char	*backup;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	if (line[count] == '\0')
		return (NULL);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free (backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = function(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = extract(line);
	return (line);
}
