/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_p.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 19:18:39 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 14:52:56 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		get_max(int a, int b);
void	print_n_chars(int n, char c);
int		get_len_uint(unsigned int n, int base);
void	print_s(char *s, int flags[], int *res);
void	print_x(unsigned int n, int flags[], int *res);

static void	print_long_p(unsigned long n, int flags[], int *res)
{
	int	num_spaces;

	num_spaces = flags[6] - 10 - get_len_uint(n / 4294967296, 16);
	if (flags[0] == 0)
		print_n_chars(num_spaces, ' ');
	flags[6] = 0;
	flags[4] = 1;
	print_x(n / 4294967296, flags, res);
	flags[4] = 0;
	flags[5] = 8;
	print_x(n % 4294967296, flags, res);
	if (flags[0] == 1)
		print_n_chars(num_spaces, ' ');
	*res += get_max(0, num_spaces);
}

void	print_p(void *ptr, int flags[], int *res)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (n == 0)
	{
		flags[5] = -1;
		print_s("(nil)", flags, res);
	}
	else if (n <= 4294967295)
	{
		flags[4] = 1;
		print_x(n, flags, res);
	}
	else
		print_long_p(n, flags, res);
}
