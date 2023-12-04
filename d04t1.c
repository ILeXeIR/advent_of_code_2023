#include "libft/libft.h"
#include <fcntl.h>

static int	get_num(char *str)
{
	int	num;

	num = str[1] - '0';
	if (*str != ' ')
		num += (*str - '0') * 10;
	return (num);
}

int	is_winner(int num, int wins[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (num == wins[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_points(int wins[10], char *line)
{
	int	res;
	int	num;

	res = 0;
	while (1)
	{
		num = get_num(line);
		if (is_winner(num, wins) == 1)
		{
			res *= 2;
			if (res == 0)
				res = 1;
		}
		if (line[2] == '\0' || line[2] == '\n')
			break ;
		line += 3;
	}
	return (res);
}

void	fill_wins(int wins[10], char *line)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		wins[i] = get_num(line);
		line += 3;
		i++;
	}
}

int	get_value(char *line)
{
	int	win[10];

	line += 10;
	fill_wins(win, line);
	line += 32;
	return (count_points(win, line));
}

int	main(void)
{
	int		res;
	int		fd;
	char	*line;

	fd = open("files/D04.txt", O_RDONLY);
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
