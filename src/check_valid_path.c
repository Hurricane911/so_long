#include "so_long.h"

void check_valid_path(t_game *game);
void find_exit(int x, int y, t_game *game);
void find_collectibles(int x, int y, t_game *game);
void scan_player(t_game *game);

void scan_player(t_game *game)
{
	game->map.player.y = 0;
	game->map.player.x = 0;
	while (game->map.player.y < game->map.rows)
	{
		while (game->map.player.x < game->map.columns)
		{
			if (game->map.full[game->map.player.y][game->map.player.x] == 'P') // Ensure case consistency
				break;
			game->map.player.x++;
		}
		if (game->map.full[game->map.player.y][game->map.player.x] == 'P') // Ensure case consistency
			break;
		game->map.player.x = 0;
		game->map.player.y++;
	}
}

void find_collectibles(int x, int y, t_game *game)
{

	char type;

	type = game->map.copy[y][x];
	if (type == 'C')
	{
		game->c_check -= 1;
		game->map.copy[y][x] = 'Z';
	}
	else if (type == 'E')
	{
		return;
	}
	else if (type == '0' || type == 'P')
		game->map.copy[y][x] = 'Z';
	else
		return;
	// Recursive calls for neighbors
	find_collectibles(x + 1, y, game);
	find_collectibles(x - 1, y, game);
	find_collectibles(x, y + 1, game);
	find_collectibles(x, y - 1, game);
}

void find_exit(int x, int y, t_game *game)
{
	char type;

	type = game->map.copy[y][x];
	if (type == 'Z')
	{
		game->map.copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		game->e_check -= 1;
		game->map.copy[y][x] = '1';
	}
	else
		return;

	// Recursive calls for neighbors
	find_exit(x + 1, y, game);
	find_exit(x - 1, y, game);
	find_exit(x, y + 1, game);
	find_exit(x, y - 1, game);
}

void check_valid_path(t_game *game)
{
	game->c_check = game->map.coins;
	game->e_check = game->map.exit;

	scan_player(game); // Locate the player

	find_collectibles(game->map.player.x, game->map.player.y, game);
	find_exit(game->map.player.x, game->map.player.y, game);

	if (game->c_check != 0 || game->e_check != 0) // Check for unreachable collectibles or exits
	{
		ft_error_msg("Error\nPath Invalid", game);
	}
}
