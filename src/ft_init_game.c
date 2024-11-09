#include "so_long.h"

void ft_init_map(t_game *game, char *av);
void ft_init_vars(t_game *game);
void ft_init_mlx(t_game *game);
void ft_init_sprites(t_game *game);
t_image ft_new_sprite(void *mlx, char *path, t_game *game);

void ft_init_map(t_game *game, char *av)
{
	char *map_temp;
	char *line_temp;
	int map_fd;

	map_fd = open(av, O_RDONLY);

	map_temp = ft_strdup(""); // map_temp init 0, empty string
	game->map.rows = 0;		  // assign row to 0

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

void ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
								   game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
	}
}

void ft_init_vars(t_game *game)
{
	game->map.players = 0;
}

void ft_init_sprites(t_game *game)
{
	void *mlx;
	mlx = game->mlx_ptr;
	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
}

t_image ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);

	return (sprite);
}
