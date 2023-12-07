#include <fcntl.h>
#include "libft/libft.h"

typedef enum e_hand {
	POINTS = 0,
	TYPE = 1,
	BID = 2,
	POS = 3
}	t_hand;

int	find_solution(int hands[1000][4])
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	while (++i < 1000)
		res += (hands[i][BID] * hands[i][POS]);
	return (res);
}

void	get_positions(int hands[1000][4])
{
	int	i;
	int	j;
	int	pos;

	i = -1;
	while (++i < 1000)
	{
		pos = 1;
		j = -1;
		while (++j < 1000)
		{
			if (hands[j][TYPE] < hands[i][TYPE]
				|| (hands[j][TYPE] == hands[i][TYPE]
				&& hands[j][POINTS] < hands[i][POINTS]))
				pos++;
		}
		hands[i][POS] = pos;
	}
}

int	get_index(char ch)
{
	int			i;
	const char	*base = "23456789TJQKA";

	i = -1;
	while (++i < 13)
	{
		if (base[i] == ch)
			return (i);
	}
	return (-10000000);
}

int	get_combination(int comb1, int comb2)
{
	if (comb1 > 3)
		return (comb1 + 1);
	if (comb1 + comb2 == 5)
		return (4);
	if (comb1 == 3)
		return (3);
	if (comb1 == 1)
		return (0);
	return (comb2);
}

void	count_same_cards(char *str, int i, int *comb)
{
	int	j;

	j = i;
	while (++j < 5)
	{
		if (str[j] == str[i])
		{
			*comb += 1;
			str[j] = 'x';
		}
	}
}

int	get_type(char *str)
{
	int	i;
	int	comb1;
	int	comb2;

	i = -1;
	comb1 = 1;
	comb2 = 1;
	while (++i < 4)
	{
		if (str[i] == 'x')
			continue ;
		if (comb1 == 1)
			count_same_cards(str, i, &comb1);
		else
			count_same_cards(str, i, &comb2);
	}
	return (get_combination(comb1, comb2));
}

int	count_points(char *str)
{
	int	res;
	int	i;

	i = -1;
	res = 0;
	while (++i < 5)
		res = res * 13 + get_index(str[i]);
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

void	fill_arr(int hands[1000][4], int fd)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 1000)
	{
		line = get_next_line(fd);
		hands[i][POINTS] = count_points(line);
		hands[i][TYPE] = get_type(line);
		hands[i][BID] = get_int(line + 6);
		free(line);
	}
}

void	solve_puzzle(int fd)
{
	int	hands[1000][4];

	fill_arr(hands, fd);
	get_positions(hands);
	ft_printf("Result: %u!\n", find_solution(hands));
}

int	main(void)
{
	int		fd;

	fd = open("files/D07.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR: Can't open file.\n");
		return (1);
	}
	solve_puzzle(fd);
	return (0);
}
