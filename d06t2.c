#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "libft/libft.h"

// x * (time - x) > distance
// -x^2 + time * x - distance > 0
// a = -1, b = time, c = -distance

long long	find_solution(long long time, long long distance)
{
	long double	x;
	long long	x1;
	long long	x2;

	x = (time - sqrt(time * time - 4 * distance)) / 2;
	x1 = (long long)floor(x + 1);
	x = (time + sqrt(time * time - 4 * distance)) / 2;
	x2 = (long long)ceil(x - 1);
	return (x2 - x1 + 1);
}

long long	parse_num(int fd)
{
	char		*line;
	long long	res;
	int			i;

	line = get_next_line(fd);
	res = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
			res = res * 10 + (line[i] - '0');
		i++;
	}
	free(line);
	return (res);
}

void	solve_puzzle(int fd)
{
	long long	time;
	long long	distance;

	time = parse_num(fd);
	distance = parse_num(fd);
	printf("Result: %lld!\n", find_solution(time, distance));
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
