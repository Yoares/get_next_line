/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:14:40 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/29 15:32:04 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t   ft_strlen(const char *s1)
{
    size_t i;
    
    i = 0;
    while (s1[i])
    {
        i++;
    } 
    return (i);
}
char    *ft_strjoin(char *s1, char *s2)
{
    size_t s1_len;
    size_t s2_len;
    char *ptr;
    
    if (!s1 && !s2)
        return (NULL);
    s1_len = 0;
    s2_len = 0;
    if (s1 != NULL)
        s1_len = ft_strlen(s1);
    if (s2 != NULL)
        s2_len = ft_strlen(s2);
    ptr = malloc(s1_len + s2_len + 1);
    if (!ptr)
        return (NULL);
    
}