/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:00 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/12/02 18:01:09 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*buffer;
	int			i;
	static char	*remainder;
	char	*line;
	char *newline_pos;
	char	*new_remainder;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((newline_pos = ft_strchr(remainder, '\n')) == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (fd == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		i++;
	}
	free (buffer);
	if (newline_pos)
	{
        line = ft_substr(remainder, 0,(newline_pos - remainder + 1));
        new_remainder = ft_substr(remainder, newline_pos - remainder + 1, ft_strlen(remainder) - (newline_pos - remainder + 1));
		free (remainder);
		remainder = new_remainder;
        return (line);
	}
	if (remainder && new_remainder)
	{
		line = ft_substr(remainder, 0, ft_strlen(remainder));
		free (remainder);
		remainder = NULL;
		return (line);
	}
	free(remainder);
	remainder = NULL;
	return (NULL);
}