/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:30:15 by joyim             #+#    #+#             */
/*   Updated: 2024/11/21 17:30:15 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_victory(t_game *game);
int		ft_close_game(t_game *game);
int		ft_error_msg(char *message, t_game *game);

int	ft_victory(t_game *game)
{
	ft_printf(CYAN "\n			Movements: %d\n" RESET, ++game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf(GREEN "\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
" RESET);
	exit (1);
}

int	ft_close_game(t_game *game)
{
	ft_printf(CYAN "Movements: %d\n" RESET, game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf(GREY "CLOSED\n" RESET);
	exit(1);
}

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("%s\n", message);
	exit (1);
}
