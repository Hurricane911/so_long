/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:07:21 by joyim             #+#    #+#             */
/*   Updated: 2024/07/29 10:48:17 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t ft_strlen(const char *s);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t n);
char *get_next_line(int fd);

#endif
