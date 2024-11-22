/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:12:57 by joyim             #+#    #+#             */
/*   Updated: 2024/11/21 19:12:57 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define IMG_HEIGHT		50
# define IMG_WIDTH		50

# define WALL			'1'
# define FLOOR			'0'
# define COINS			'C'
# define PLAYER			'P'
# define MAP_EXIT		'E'

# define KEY_W 			119
# define KEY_A 			97
# define KEY_S 			115
# define KEY_D 			100

# define KEY_UP 		65362
# define KEY_LEFT 		65361
# define KEY_RIGHT 		65363
# define KEY_DOWN 		65364

# define KEY_Q			113
# define KEY_ESC 		65307

# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

# define WALL_XPM "assets/sprites/wall.xpm"
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/back.xpm"
# define OPEN_EXIT_XPM "assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/exit-closed.xpm"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int			x;
	int			y;
}	t_positon;

typedef struct s_image
{
	void		*xpm_ptr;
	int			x;
	int			y;
}	t_image;

typedef struct s_map
{
	char		**full;
	char		**copy;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	int			c_check;
	int			e_check;
	int			c;
	int			e;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

void	ft_init_map(t_game *game, char *av);
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);

int		ft_render_map(t_game *game);
void	ft_render_sprite(t_game *game, t_image sprite, int line, int column);
void	ft_render_player(t_game *game, int y, int x);

int		ft_handle_input(int keysym, t_game *game);

void	ft_print_file(char *av);
void	ft_print_movements(t_game *game);
void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite);

char	*ft_strappend(char **s1, const char *s2);

void	ft_check_command_line_arguments(int ac, char **av, t_game *game);
void	ft_check_for_empty_line(char *map, t_game *game);
int		ft_error_msg(char *message, t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);
void	check_size(t_game *game);
void	handle_exit_err(t_game *game);
int		ft_rd_map(t_game *game, char *av);
void	ft_check_map_case(char *map, t_game *game);
char	*ft_init_map_true(char map_fd, char *map_temp, t_game *game);
char	*ft_line_temp(char	*line_temp);
void	ft_count_map_cell(t_game *game, int x, int y);

void	ft_free_map(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);

void	ft_destroy_images(t_game *game);
int		ft_victory(t_game *game);
int		ft_close_game(t_game *game);

void	check_valid_path(t_game *game);
void	find_exit(int x, int y, t_game *game);
void	find_collectibles(int x, int y, t_game *game);
void	scan_player(t_game *game);

#endif