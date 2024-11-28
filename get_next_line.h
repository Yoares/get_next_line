/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:15:10 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/11/28 18:32:42 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include<stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif



char    *get_next_line(int fd);
#endif