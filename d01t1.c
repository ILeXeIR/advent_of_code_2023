#include "libft/libft.h"
# include <fcntl.h>

int	get_value(char *line)
{
	int	value;
	int	i;

	while (!ft_isdigit(*line))
		line++;
	value = (*line - '0') * 10;
	i = ft_strlen(line) - 1;
	while (!ft_isdigit(line[i]))
		i--;
	value += line[i] - '0';
	return (value);
}

int	main(void)
{
	int		res;
	int		fd;
	char	*line;

	fd = open("files/D01_task1.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR: Can't open file.\n");
		return (1);
	}
	line = get_next_line(fd);
	res = 0;
	while (line != NULL)
	{
		res += get_value(line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("Result: %d!\n", res);
	return (0);
}
