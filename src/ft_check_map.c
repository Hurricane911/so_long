/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:21:55 by joyim             #+#    #+#             */
/*   Updated: 2024/11/21 17:21:55 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);

void	ft_check_map(t_game *game)
{
	check_size(game);
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
	check_valid_path(game);
}

void	check_size(t_game *game)
{
	size_t	len;
	int		i;

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

void	ft_check_columns(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error_msg("Error\nInvalid Map. "
				"Wall missing first column.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error_msg("Error\nInvalid Map. "
				"Wall missing last column.", game);
		i++;
	}
}

void	ft_check_rows(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error_msg("Error\nWall missing first row.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_msg("Error\nInvalid Map. "
				"Wall missing last row.", game);
		i++;
	}
}
