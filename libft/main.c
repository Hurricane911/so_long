#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;

	// Manually specify the file name
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	// Read lines from the file
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line); // Free each line after printing
	}

	// Close the file descriptor
	close(fd);
	return (0);
}
