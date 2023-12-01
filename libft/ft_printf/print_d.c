/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 16:38:28 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 14:52:22 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				get_max(int a, int b);
unsigned int	set_abs(int n);
void			print_n_chars(int n, char c);
int				get_len_uint(unsigned int n, int base);
void			print_uint(unsigned int n);

static void	print_sign(int n, int len, int flags[])
{
	if (n < 0)
		write(1, "-", 1);
	else if (flags[2] == 1)
		write(1, "+", 1);
	else if (flags[3] == 1)
		write(1, " ", 1);
	else if (flags[0] == 0 && flags[1] == 1 && flags[5] < 0 && flags[6] > len)
		write(1, "0", 1);
	else if (flags[0] == 0 && flags[6] > flags[5] && flags[6] > len)
		write(1, " ", 1);
}

static int	printed_chars_d(int precision, int num, int flags[])
{
	if (num == 0 && flags[5] == 0)
		precision = 0;
	if (flags[6] > precision)
		return (flags[6]);
	else if (num < 0 || flags[2] == 1 || flags[3] == 1)
		return (precision + 1);
	else
		return (precision);
}

static int	set_precision_d(int flags[], int len)
{
	int	precision;

	precision = flags[5];
	if (flags[0] == 0 && flags[1] == 1 && flags[5] < 0)
		precision = flags[6] - 1;
	if (precision < len)
		precision = len;
	return (precision);
}

static void	print_no_zero(int flags[])
{
	if (flags[0] == 0)
		print_n_chars(flags[6] - 1, ' ');
	if (flags[2] == 1)
		write(1, "+", 1);
	else if (flags[6] > 0 || flags[3] == 1)
		write(1, " ", 1);
	if (flags[0] == 1)
		print_n_chars(flags[6] - 1, ' ');
}

void	print_d(int n, int flags[], int *res)
{
	int				precision;
	int				len;
	unsigned int	abs;

	abs = set_abs(n);
	len = get_len_uint(abs, 10);
	precision = set_precision_d(flags, len);
	*res += printed_chars_d(precision, n, flags);
	if (n == 0 && flags[5] == 0)
	{
		print_no_zero(flags);
		return ;
	}
	if (flags[0] == 0)
		print_n_chars(flags[6] - precision - 1, ' ');
	print_sign(n, len, flags);
	print_n_chars(precision - len, '0');
	print_uint(abs);
	if (flags[0] == 1)
	{
		print_n_chars(flags[6] - precision - 1, ' ');
		if (n >= 0 && flags[2] == 0 && flags[3] == 0 && precision < flags[6])
			write(1, " ", 1);
	}
}
