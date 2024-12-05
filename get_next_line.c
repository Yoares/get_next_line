/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:00 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/12/05 21:11:51 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_manage(int fd, char *full_line)
{
    char *buffer;
    ssize_t byte_read;
    char *temp;

    while (1)
    {
        buffer = ft_calloc(BUFFER_SIZE +1 , 1);
        if (!buffer)
            return(NULL);
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read <= 0)
        {
            free(buffer);
            break;
        }
        buffer[byte_read] = '\0';
        temp = full_line;
        full_line = ft_strjoin(full_line, buffer);
        free(buffer);
        if (temp)
            free(temp);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    return (full_line);
}
char *return_line(char *full_line)
{
    size_t i;
    char    *line;
    
    i = 0;
    while(full_line[i] && full_line[i] != '\n')
        i++;
    line = ft_calloc(i + 1 + (full_line[i] == '\n'), sizeof(char));
    if (!line)
        return (NULL);
    ft_memcpy(line, full_line, i + (full_line[i] == '\n'));
    return (line);
}
int checknl(char *s )
{
    int i = 0 ;
    while(s[i] != '\n' && s[i])
    {
        i++;
    }
    return i + (s[i] == '\n');
}
char *trim(char *s, int i)
{
    char *ns;
    int len = ft_strlen(s) - i;

    if (len <= 0)
    {
        free(s);
        return (NULL);
    }
    ns = ft_calloc(len + 1, 1);
    if (!ns)
        return (NULL);
    ft_memcpy(ns, s + i, len);
    free(s);
    return (ns);
}

char *get_next_line(int fd)
{
    static  char *full_line;
    char    *new_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    full_line = read_manage(fd, full_line);
    if (!full_line)
        return (NULL);
    if (full_line)
        new_line = return_line(full_line);
    full_line  = trim(full_line , checknl(full_line));
    if (!new_line && !full_line)
    {
        free(full_line);
        full_line = NULL;
    }
    return (new_line);
}
