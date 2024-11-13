#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx/mlx.h"
#include "../libft/libft.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define IMG_HEIGHT 100
#define IMG_WIDTH 100

#define WALL '1'
#define FLOOR '0'
#define COINS 'C'
#define PLAYER 'P'
#define MAP_EXIT 'E'

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define KEY_UP 65362
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_DOWN 65364

#define KEY_Q 113
#define KEY_ESC 65307

#define PLAYER_FRONT_XPM "src/ditto2.xpm"

#define GREEN "\033[0;32m"
#define RED "\033[1;31m"
#define GREY "\033[0;90m"
#define CYAN "\033[1;96m"
#define RESET "\033[0m"

typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct s_position
{
	int x;
	int y;
} t_positon;

typedef struct s_image
{
	void *xpm_ptr;
	int x;
	int y;
} t_image;

typedef struct s_map
{
	char **full;
	int rows;
	int columns;
	int coins;
	int exit;
	int players;
	t_positon player;
} t_map;

typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
	int movements;
	int player_sprite;
	t_map map;
	t_bool map_alloc;
	t_image wall;
	t_image floor;
	t_image coins;
	t_image open_exit;
	t_image exit_closed;
	t_image player_front;
	t_image player_left;
	t_image player_right;
	t_image player_back;
} t_game;

// init
void ft_init_map(t_game *game, char *av);
void ft_init_vars(t_game *game);
void ft_init_mlx(t_game *game);
void ft_init_sprites(t_game *game);
t_image ft_new_sprite(void *mlx, char *path, t_game *game);

// utils
char *ft_strappend(char **s1, const char *s2);

// error checking
void ft_check_command_line_arguments(int ac, char **av, t_game *game);
int ft_error_msg(char *message, t_game *game);

// free_memory
void ft_free_map(t_game *game);

#endif