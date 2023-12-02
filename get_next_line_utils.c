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
	if(!str || *str == '\0')
		return 0;

	const char *end = str;
	while(*end)
		end++;
	return ((size_t)(end - str));
}

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*copy;
	size_t	i;

	len = 0;
	i = 0;
	while (len < n && str[len] != '\0')
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	while (i < n)
	{
		copy[i] = str[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

char	*ft_strjoin(char *join, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!join || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(join) + ft_strlen(buff)) + 1));
	if (!str)
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
