/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:15:10 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/12/05 16:05:23 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include<stdlib.h>
# include<unistd.h> 
# include <stdint.h>
#include <limits.h>
#include <stdio.h> 
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 225
#endif



char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
size_t   ft_strlen(char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif