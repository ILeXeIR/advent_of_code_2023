/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 16:42:55 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 14:52:34 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	set_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	return ((unsigned int)(n));
}

int	get_num(const char *fmt, int *n)
{
	int	value;

	value = 0;
	while ('0' <= fmt[*n] && fmt[*n] <= '9')
	{
		value = value * 10 + (fmt[*n] - '0');
		*n += 1;
	}
	return (value);
}

void	print_n_chars(int n, char c)
{
	while (n-- > 0)
		write(1, &c, 1);
}

int	get_len_uint(unsigned int n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
