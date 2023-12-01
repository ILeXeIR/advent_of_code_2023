#include "libft/libft.h"
# include <fcntl.h>

int	get_word_num(char *line)
{
	int		i;
	char	dict[9][6] = 	{"one", "two", "three", "four", "five",
							"six", "seven", "eight", "nine"};

	i = 0;
	while (i < 9)
	{
		if (ft_strncmp(line, dict[i], ft_strlen(dict[i])) == 0)
			return (i + 1);
		i++;
	}
	return (-1);
}

int	get_digit(char *line, int sign)
{
	int	num;

	while (*line)
	{
		if (ft_isdigit(*line))
			return (*line - '0');
		num = get_word_num(line);
		if (num > 0)
			return (num);
		line += sign;
	}
	return (-10000000);
}

int	get_value(char *line)
{
	int	value;
	int	len;

	value = get_digit(line, 1) * 10;
	len = ft_strlen(line);
	value += get_digit(line + len - 1, -1);
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
