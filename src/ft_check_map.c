
#include "so_long.h"

void ft_check_map(t_game *game);
void ft_check_rows(t_game *game);
void ft_check_columns(t_game *game);
void ft_count_map_parameters(t_game *game);
void ft_verify_map_parameters(t_game *game);

void ft_check_map(t_game *game)
{
	check_size(game);
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
}

void check_size(t_game *game)
{
	size_t len;
	int i;

	i = 0;
	len = ft_strlen(game->map.full[i]);
	i = 1;
	while (game->map.full[i])
	{
		if (ft_strlen(game->map.full[i]) != len)
			ft_error_msg("Error\nMap is not rectangular", game);
		else
			i++;
	}
}

void ft_check_rows(t_game *game)
{
	int i;

	i = 0;
	while (game->map.full[i] != NULL)
	{
		printf("%s\n", game->map.full[i]);
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error_msg("Error\nInvalid Map. Wall missing first column.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error_msg("Error\nInvalid Map. Wall missing last column.", game);
		i++;
	}
}

void ft_check_columns(t_game *game)
{
	int i;

	i = 0;
	// while (game->map.full[i] != NULL)
	// {
	// 	printf("%s\n", game->map.full[i]);
	// 	i++;
	// }
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error_msg("Error\nInvalid Map. Wall missing first row.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_msg("Error\nInvalid Map. Wall missing last row.", game);
		i++;
	}
}

void ft_count_map_parameters(t_game *game)
{
	int x;
	int y;
	int exit_count;

	exit_count = 0;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error_msg("Error\nInvalid Map. Not expected map parameter.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full[y][x] == MAP_EXIT)
			{
				game->map.exit++;
				exit_count++;
				if (exit_count > 1)
					ft_error_msg("Error\nDuplicate Exit.", game);
			}
			x++;
		}
		y++;
	}
}

void ft_verify_map_parameters(t_game *game)
{
	if (game->map.coins == 0)
		ft_error_msg("Error\nInvalid Map. No Coins", game);
	else if (game->map.exit == 0)
		ft_error_msg("Error\nInvalid Map. No Exit.", game);
	else if (game->map.players != 1)
		ft_error_msg("Error\nInvalid Map. Player error.", game);
}
