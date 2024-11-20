#include "so_long.h"
#include <stdio.h>
#include <string.h>

void ft_check_command_line_arguments(int ac, char **av, t_game *game);
void ft_init_map(t_game *game, char *av);
void ft_check_for_empty_line(char *map, t_game *game);

void ft_check_command_line_arguments(int ac, char **av, t_game *game)
{
	int map_parameter_len;

	game->map_alloc = false;

	if (ac > 2)
		ft_error_msg("Error\nTwo Arg only", game);
	if (ac < 2)
		ft_error_msg("Error\nmap file missing", game);
	map_parameter_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Error\n(.ber only)", game);
}

void ft_init_map(t_game *game, char *av)
{
	char *map_temp;
	char *line_temp;
	int map_fd;
	char buffer[1];
	ssize_t bytes_read;
	printf("Opening file: %s\n", av);
	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("Error\nFile does not exist", game);

	bytes_read = read(map_fd, buffer, 1);
	if (bytes_read == 0)
		ft_error_msg("Error\nMap is empty", game);
	lseek(map_fd, 0, SEEK_SET);

	map_temp = ft_strdup("");
	game->map.rows = 0; // init map row
	game->map.columns = 0;

	while (true)
	{
		line_temp = get_next_line(map_fd); // init buffer
		if (line_temp == NULL)
			break;
		int i = 0, j = 0;
		while (line_temp[i] != '\0')
		{
			if (line_temp[i] != '\r')
			{
				line_temp[j] = line_temp[i];
				j++;
			}
			i++;
		}
		line_temp[j] = '\0';
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	// printf("Map contents:\n%s\n", map_temp);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map.copy = ft_split(map_temp, '\n');

	game->map_alloc = true;
	free(map_temp);
}

void ft_check_for_empty_line(char *map, t_game *game)
{
	int i;

	i = 0;
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