#include "so_long.h"

int ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("error\n", message);
	exit(EXIT_FAILURE);
}