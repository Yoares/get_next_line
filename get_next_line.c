/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:00 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/29 15:14:22 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static  char    *remainder;
    ssize_t    bytes_read;
    char    *buffer;
    int i;
    
    i = 0;
    remainder = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (remainder[i] != '\n')
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (fd == -1)
        {
            free(buffer);
            return (NULL);
        }
        if (bytes_read == 0)
            break;
        buffer[bytes_read] = '\0';
        remainder = strjoin()
        i++;
    }
    
}

