/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:37:42 by joyim             #+#    #+#             */
/*   Updated: 2024/11/21 17:37:42 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);

void	ft_free_all_allocated_memory(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coins.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
}

void	ft_free_map(t_game *game)
{
	int		i;

	i = 0;
	if (game->map.full)
	{
		while (game->map.full[i])
		{
			free(game->map.full[i]);
			i++;
		}
		free(game->map.full);
	}
	i = 0;
	if (game->map.copy[i])
	{
		while (game->map.copy[i])
		{
			free(game->map.copy[i]);
			i++;
		}
		free(game->map.copy);
	}
}
