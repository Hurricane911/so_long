#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;

	t_game *game;

	game = malloc(sizeof(t_game));

	ft_init_map(game, av[1]);
	ft_init_vars(game);
	// ft_check_map(game);
	ft_init_mlx(game);
	ft_init_sprites(game);

	mlx_loop(game->mlx_ptr);
}