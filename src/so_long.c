#include "so_long.h"

// int main(void)
// {
// 	void *mlx;
// 	void *mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	(void)mlx_win;
// 	mlx_loop(mlx);
// }

int main(void)
{
	void *mlx;
	void *img;
	char *relative_path = "./win.xpm";
	int img_width;
	int img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	(void)img;
	mlx_loop(mlx);
}
