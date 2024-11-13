#include "so_long.h"

int main(int ac, char **av)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	ft_check_command_line_arguments(ac, av, game);
	ft_init_map(game, av[1]);
	ft_init_mlx(game);

	mlx_loop(game->mlx_ptr);
}
