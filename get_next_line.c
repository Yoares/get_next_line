/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:00 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/28 18:48:40 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static  char    *remainder;
    static  int i;
    
    remainder = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    while (remainder[i] != '\n')
    {
        
        i++;
    }

}