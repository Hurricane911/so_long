/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:07:46 by joyim             #+#    #+#             */
/*   Updated: 2024/07/26 17:07:49 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char *ft_strdup(const char *s1)
{
	char *str;
	size_t i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t i;
	size_t j;
	char *ptr;
	size_t total;

	total = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * total + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		ptr[i++] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i++] = s2[j];
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_len;
	size_t sub_len;
	char *substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = 0;
	if (start < s_len)
		sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	substr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, sub_len);
	substr[sub_len] = '\0';
	return (substr);
}

// static char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (unsigned char)c)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	if (c == '\0')
// 	{
// 		return ((char *)&s[i]);
// 	}
// 	return (NULL);
// }
