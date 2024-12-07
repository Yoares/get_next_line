/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:52:13 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/12/07 23:14:59 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **buff)
{
	if (!*buff)
		return ;
	free(*buff);
}

char	*read_manage(int fd, char *full_line)
{
	char		*buffer;
	ssize_t		byte_read;
	char		*temp;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (ft_free(&buffer), ft_free(&full_line), NULL);
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		temp = full_line;
		full_line = ft_strjoin(full_line, buffer);
		if (temp)
			ft_free(&temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ft_free(&buffer);
	return (full_line);
}

char	*return_line(char *full_line)
{
	size_t	i;
	char	*line;

	i = 0;
	while (full_line[i] && full_line[i] != '\n')
		i++;
	line = ft_calloc(i + 1 + (full_line[i] == '\n'), sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, full_line, i + (full_line[i] == '\n'));
	return (line);
}

char	*trim(char *s)
{
	char	*ns;
	int		len;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	i++;
	len = ft_strlen(s) - i;
	if (len <= 0)
	{
		ft_free(&s);
		return (NULL);
	}
	ns = ft_calloc(len + 1, 1);
	if (!ns)
		return (NULL);
	ft_memcpy(ns, s + i, len);
	ft_free(&s);
	return (ns);
}

char	*get_next_line(int fd)
{
	static char	*full_line[MAX_FD];
	char		*new_line;

	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || fd > MAX_FD)
		return (NULL);
	full_line[fd] = read_manage(fd, full_line[fd]);
	if (!full_line[fd])
		return (NULL);
	if (full_line[fd])
		new_line = return_line(full_line[fd]);
	full_line[fd] = trim(full_line[fd]);
	if (!new_line && !full_line[fd])
	{
		ft_free(&full_line[fd]);
		full_line[fd] = NULL;
	}
	return (new_line);
}