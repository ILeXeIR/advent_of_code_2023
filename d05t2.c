#include "libft/libft.h"
#include <fcntl.h>
#include <limits.h>

unsigned int	find_step(unsigned int num, unsigned int map[50][3], int size)
{
	unsigned int	step;
	int				i;

	i = -1;
	step = UINT_MAX;
	while (++i < size)
	{
		if (num < map[i][1] && step > map[i][1] - num)
			step = map[i][1] - num;
	}
	return (step);
}

int	fit_range(unsigned int num, unsigned int row[3])
{
	if (row[1] <= num && num < row[1] + row[2])
		return (1);
	return (0);
}

unsigned int	get_location(unsigned int num, unsigned int maps[7][50][3],
	int sizes[8], unsigned int *step)
{
	int				i;
	int				j;
	unsigned int	cur_step;
	unsigned int	min_step;

	i = -1;
	min_step = UINT_MAX;
	while (++i < 7)
	{
		j = -1;
		cur_step = 0;
		while (++j < sizes[i])
		{
			if (fit_range(num, maps[i][j]) == 1)
			{
				cur_step = maps[i][j][1] + maps[i][j][2] - num;
				num = maps[i][j][0] + (num - maps[i][j][1]);
				break ;
			}
		}
		if (cur_step == 0)
			cur_step = find_step(num, maps[i], sizes[i]);
		if (min_step > cur_step)
			min_step = cur_step;
	}
	if (*step < UINT_MAX - min_step)
		*step += min_step;
	else
		*step = UINT_MAX;
	return (num);
}

unsigned int	find_solution(unsigned int seeds[50],
	unsigned int maps[7][50][3], int sizes[8])
{
	unsigned int	location;
	unsigned int	min_loc;
	int				i;
	unsigned int	cur_num;
	unsigned int	step;
	unsigned int	temp;

	i = -1;
	min_loc = UINT_MAX;
	while (++i * 2 < sizes[7])
	{
		step = 0;
		while (step < seeds[i * 2 + 1])
		{
			temp = step;
			location = get_location(seeds[i * 2] + step, maps, sizes, &step);
			if (location < min_loc)
				min_loc = location;
		}
	}
	return (min_loc);
}

unsigned int	get_uint(char *str)
{
	long long	res;

	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		if (res > UINT_MAX)
			ft_printf("Error: Number out of range UINT.\n");
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

int	fill_seeds(unsigned int seeds[50], int fd)
{
	char	*line;
	char	**array;
	int		i;

	line = get_next_line(fd);
	array = ft_split(line + 6, ' ');
	free(line);
	i = -1;
	while (array[++i] != NULL)
		seeds[i] = get_uint(array[i]);
	free_array(array);
	line = get_next_line(fd);
	free(line);
	return (i);
}

void	fill_row(unsigned int row[3], char *line)
{
	int		i;
	char	**array;

	i = -1;
	array = ft_split(line, ' ');
	while (array[++i] != NULL)
		row[i] = get_uint(array[i]);
	free_array(array);
}

int	fill_map(unsigned int map[50][3], int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL && *line != '\n')
	{
		fill_row(map[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	return (i);
}

void	solve_puzzle(int fd)
{
	unsigned int	maps[7][50][3];
	unsigned int	seeds[50];
	int				i;
	int				sizes[8];

	sizes[7] = fill_seeds(seeds, fd);
	i = -1;
	while (++i < 7)
		sizes[i] = fill_map(maps[i], fd);
	ft_printf("Result: %u!\n", find_solution(seeds, maps, sizes));
}

int	main(void)
{
	int		fd;

	fd = open("files/D05.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR: Can't open file.\n");
		return (1);
	}
	solve_puzzle(fd);
	return (0);
}
