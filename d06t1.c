#include <fcntl.h>
#include <math.h>
#include "libft/libft.h"

// x * (time - x) > distance
// -x^2 + time * x - distance > 0
// a = -1, b = time, c = -distance

int	find_solution(int time[4], int distance[4])
{
	int		res;
	double	x;
	int		x1;
	int		x2;
	int		i;

	i = -1;
	res = 1;
	while (++i < 4)
	{
		x = (time[i] - sqrt(time[i] * time[i] - 4 * distance[i])) / 2;
		x1 = (int)floor(x + 1);
		x = (time[i] + sqrt(time[i] * time[i] - 4 * distance[i])) / 2;
		x2 = (int)ceil(x - 1);
		// ft_printf("%d, %d, %d\n", x1, x2, x2 - x1 + 1);
		res *= x2 - x1 + 1;
	}
	return (res);
}

int	get_int(char *str)
{
	int	res;

	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

void	fill_arr(int int_arr[4], int fd)
{
	char	*line;
	char	**array;
	int		i;

	line = get_next_line(fd);
	array = ft_split(line + 10, ' ');
	free(line);
	i = -1;
	while (array[++i] != NULL)
		int_arr[i] = get_int(array[i]);
	free_array(array);
}

void	solve_puzzle(int fd)
{
	int	time[4];
	int	distance[4];

	fill_arr(time, fd);
	fill_arr(distance, fd);
	ft_printf("Result: %u!\n", find_solution(time, distance));
}

int	main(void)
{
	int		fd;

	fd = open("files/D06.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR: Can't open file.\n");
		return (1);
	}
	solve_puzzle(fd);
	return (0);
}
