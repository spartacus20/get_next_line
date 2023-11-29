/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/22 12:44:10 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/22 12:44:10 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;

	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *str_dest;
	const char *str_src;

	if ((!dest && !src) || n == 0)
		return (dest);
	str_dest = dest;
	str_src = src;
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}

// char *ft_strndup(const char *str, size_t n)
// {
// 	size_t len;
// 	char *copy;

// 	len = 0;
// 	while(len < n && str[len])
// 		len++;

// 	if ((copy = malloc(len + 1)) == NULL)
// 		return (NULL);
// 	ft_memcpy(copy, str, len);
// 	copy[len] = '\0';
// 	return (copy);
// }

char *ft_strndup(const char *str, size_t n) {
    size_t len = 0;

    while (len < n && str[len] != '\0') {
        len++;
    }

    char *copy = malloc(len + 1);

    if (!copy) {
        return NULL;  // Memory allocation failed
    }

    ft_memcpy(copy, str, len);
    copy[len] = '\0';

    return copy;
}

char	*ft_strjoin(char *join, char *buff)
{
	size_t i;
	size_t j;
	char *str;

	if (!join || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(join) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);

	i = -1;
	j = 0;
	if (join)
		while (join[++i] != '\0')
			str[i] = join[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(join);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}
