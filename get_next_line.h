/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:15:10 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/12/02 17:40:24 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include<stdlib.h>
# include<unistd.h> 
# include <stdint.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 255
#endif



char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t   ft_strlen(const char *s1);
char	*ft_strchr(const char *s, int c);
#endif