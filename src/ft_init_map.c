/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:11:00 by joyim             #+#    #+#             */
/*   Updated: 2024/11/21 18:11:00 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_command_line_arguments(int ac, char **av, t_game *game);
void	ft_init_map(t_game *game, char *av);
void	ft_check_for_empty_line(char *map, t_game *game);

void	ft_check_command_line_arguments(int ac, char **av, t_game *game)
{
	int		map_parameter_len;

	game->map_alloc = false;
	if (ac > 2)
		ft_error_msg("Error\nTwo Arg only", game);
	if (ac < 2)
		ft_error_msg("Error\nmap file missing", game);
	map_parameter_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_parameter_len - 4], ".ber", 4) ||
		av[1][0] == '.' || av[1][map_parameter_len - 5] == '/')
		ft_error_msg("Error\nInvalid map file"
			"(must be a valid .ber file)", game);
}

void	ft_init_map(t_game *game, char *av)
{
	char		*map_temp;
	int			map_fd;

	map_fd = ft_rd_map(game, av);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	game->map.columns = 0;
	map_temp = ft_init_map_true(map_fd, map_temp, game);
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map.copy = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int		i;

	i = 0;
	ft_check_map_case(map, game);
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Error\nInvalid map. Map empty line at middle.", game);
		}
		if (map[i] == '\r')
		{
			free(map);
			ft_error_msg("Error\nInvalid map. have carriage return.", game);
		}
		i++;
	}
}
