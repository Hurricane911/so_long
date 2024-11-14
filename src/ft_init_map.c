#include "so_long.h"

void ft_check_command_line_arguments(int ac, char **av, t_game *game);
void ft_init_map(t_game *game, char *av);
void ft_check_for_empty_line(char *map, t_game *game);

void ft_check_command_line_arguments(int ac, char **av, t_game *game)
{
	int map_parameter_len;

	game->map_alloc = false;
	if (ac > 2)
		ft_error_msg("too many arg, two only", game);
	if (ac < 2)
		ft_error_msg("map file is missing", game);
	map_parameter_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extension is wrong (.ber only)", game);
}

void ft_init_map(t_game *game, char *av)
{
	char *map_temp;
	char *line_temp;
	int map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldnt be opened", game);

	map_temp = ft_strdup("");
	game->map.rows = 0;

	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void ft_check_for_empty_line(char *map, t_game *game)
{
	int i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map.\
The map have an empty line right at the beginning.",
					 game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map. \
The map have an empty line at the end.",
					 game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map. \
The map have an empty line at the middle.",
						 game);
		}
		i++;
	}
}