/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:00 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/12/05 15:11:36 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_newline(int fd, char full_line)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t byte_read;
    
    while (1)
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read <= 0)
            break;
        buffer[byte_read] = '\0';
        full_line = ft_strjoin(full_line, buffer);

        if (ft_strchr(buffer, '\n'))
            break;
    }
    return (full_line);
}

char *get_next_line(int fd)
{
    static  char *full_line;
    char    *new_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    full_line = check_newline(fd, full_line);
    if (!full_line)
        return (NULL);
}
