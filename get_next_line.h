/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:15:10 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/29 15:14:33 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include<stdlib.h>
# include<unistd.h> 
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif



char    *get_next_line(int fd);
char    *ft_strjoin(const char *s1, const char *s2);
#endif