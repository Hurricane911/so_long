/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:59:17 by joyim             #+#    #+#             */
/*   Updated: 2024/11/21 20:59:17 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_file(char *av);

int	ft_rd_map(t_game *game, char *av)
{
	int			map_fd;
	char		buffer[1];
	ssize_t		bytes_read;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("Error\nFile does not exist", game);
	bytes_read = read(map_fd, buffer, 1);
	if (bytes_read == 0)
	{
		close(map_fd);
		ft_error_msg("Error\nMap is empty", game);
	}
	lseek(map_fd, 0, SEEK_SET);
	return (map_fd);
}

void	ft_print_file(char *av)
{
	char	*words;
	int		i;

	i = 0;
	words = (char *)malloc((ft_strlen(av) + 1) * sizeof(char));
	if (words == NULL)
	{
		ft_error_msg("Error\nMemory allocation failed.", NULL);
		return ;
	}
	while (av[i] != '\0')
	{
		words[i] = av[i];
		i++;
	}
	words[i] = '\0';
	ft_printf("Opening file: %s\n", words);
	free(words);
}
