/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 17:15:36 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 14:52:42 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		get_max(int a, int b);
void	print_n_chars(int n, char c);
int		get_len_uint(unsigned int n, int base);

static void	print_x_num(unsigned int n, int letter)
{
	char	ch;

	if (n < 10)
	{
		ch = n + '0';
		write(1, &ch, 1);
	}
	else if (n < 16)
	{
		ch = n + (letter - 10);
		write(1, &ch, 1);
	}
	else
	{
		print_x_num(n / 16, letter);
		print_x_num(n % 16, letter);
	}
}

static void	print_hex_num(unsigned int n, int zeros, int prefix, int *res)
{
	if (prefix == 1 && n > 0)
	{
		write(1, "0x", 2);
		*res += 2;
	}
	else if (prefix == 3 && n > 0)
	{
		write(1, "0X", 2);
		*res += 2;
	}
	print_n_chars(zeros, '0');
	if (prefix < 2)
		print_x_num(n, 'a');
	else
		print_x_num(n, 'A');
}

void	print_x(unsigned int n, int flags[], int *res)
{
	int	precision;
	int	width;
	int	len;

	len = get_len_uint(n, 16);
	precision = flags[5];
	width = flags[6];
	if (flags[4] % 2 == 1 && n > 0)
		width -= 2;
	if (flags[0] == 0 && flags[1] == 1 && flags[5] < 0)
		precision = width;
	precision = get_max(len, precision);
	if (n == 0 && flags[5] == 0)
		print_n_chars(width, ' ');
	else if (flags[0] == 0)
	{
		print_n_chars(width - precision, ' ');
		print_hex_num(n, precision - len, flags[4], res);
	}
	else
	{
		print_hex_num(n, precision - len, flags[4], res);
		print_n_chars(width - precision, ' ');
	}
	*res += get_max(precision, width);
}

void	print_big_x(unsigned int n, int flags[], int *res)
{
	flags[4] += 2;
	print_x(n, flags, res);
}
