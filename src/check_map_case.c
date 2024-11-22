/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:31:42 by joyim             #+#    #+#             */
/*   Updated: 2024/11/22 19:31:42 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_init_map_true(char map_fd, char *map_temp, t_game *game);
char	*ft_line_temp(char	*line_temp);

void	ft_check_map_case(char *map, t_game *game)
{
	if (map[0] == '\0')
	{
		free(map);
		ft_error_msg("Error\nMap is Empty", game);
	}
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Error\nInvalid map. Map empty line first row.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error_msg("Error\nInvalid map. Map empty line last row", game);
	}
}

char	*ft_init_map_true(char map_fd, char *map_temp, t_game *game)
{
	char	*line_temp;

	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		line_temp = ft_line_temp(line_temp);
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	return (map_temp);
}

char	*ft_line_temp(char	*line_temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line_temp[i] != '\0')
	{
		if (line_temp[i] != '\r')
		{
			line_temp [j] = line_temp [i];
			j++;
		}
		i++;
	}
	line_temp[j] = '\0';
	return (line_temp);
}
