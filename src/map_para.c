/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_para.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:30:37 by joyim             #+#    #+#             */
/*   Updated: 2024/11/21 20:30:37 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);

void	ft_count_map_parameters(t_game *game)
{
	int		x;
	int		y;
	int		exit_count;

	exit_count = 0;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error_msg("Error\nInvalid Map. \
							Not expected map parameter.", game);
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

void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.coins == 0)
		ft_error_msg("Error\nInvalid Map. No Coins", game);
	else if (game->map.exit == 0)
		ft_error_msg("Error\nInvalid Map. No Exit.", game);
	else if (game->map.players != 1)
		ft_error_msg("Error\nInvalid Map. Player error.", game);
}
