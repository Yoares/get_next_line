/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:14:40 by ykhoussi          #+#    #+#             */
/*   Updated: 2024/12/02 17:40:16 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t   ft_strlen(const char *s1)
{
    size_t i;
    
    i = 0;
    while (s1[i])
    {
        i++;
    } 
    return (i);
}

char    *ft_strcpy(char *s1, char *s2)
  {
      size_t i;
 
      i = 0;
      while (s2[i])
      {
          s1[i] = s2[i];
          i++;
      }
      s1[i] = '\0';
      return (s1);
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
    if (s1)
        ft_strcpy(ptr, s1);
    if (s2)
        ft_strcpy(ptr + s1_len, s2);
    return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*p;

	if (!s)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		return (ft_strdup(""));
	}
	else if (start + len > s_len)
	{
		len = s_len - start;
	}
	p = (char *)malloc(len + 1);
	if (!p)
	{
		return (NULL);
	}
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	if (size != 0 && (count > SIZE_MAX / size))
		return (NULL);
	s = (unsigned char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}