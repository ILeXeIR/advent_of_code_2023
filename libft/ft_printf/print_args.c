/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 17:24:59 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 14:51:59 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		get_max(int a, int b);
void	print_n_chars(int n, char c);
int		get_len_uint(unsigned int n, int base);
void	print_d(int n, int flags[], int *res);
void	print_p(void *ptr, int flags[], int *res);
void	print_x(unsigned int n, int flags[], int *res);
void	print_big_x(unsigned int n, int flags[], int *res);

static void	print_c(unsigned char c, int flags[], int *res)
{
	if (flags[0] == 0)
		print_n_chars(flags[6] - 1, ' ');
	write(1, &c, 1);
	*res += 1;
	if (flags[0] == 1)
		print_n_chars(flags[6] - 1, ' ');
	if (flags[6] - 1 > 0)
		*res += flags[6] - 1;
}

void	print_s(char *s, int flags[], int *res)
{
	int	width;
	int	len;

	if (s == NULL)
	{
		if (flags[5] < 0 || flags[5] > 5)
			print_s("(null)", flags, res);
		else
			print_s("", flags, res);
		return ;
	}
	len = ft_strlen(s);
	if (0 <= flags[5] && flags[5] < len)
		len = flags[5];
	width = flags[6];
	if (flags[0] == 0)
		print_n_chars(width - len, ' ');
	write(1, s, len);
	if (flags[0] == 1)
		print_n_chars(width - len, ' ');
	*res += get_max(len, width);
}

void	print_uint(unsigned int n)
{
	char	ch;

	if (n < 10)
	{
		ch = n + '0';
		write(1, &ch, 1);
	}
	else
	{
		print_uint(n / 10);
		print_uint(n % 10);
	}
}

static void	print_u(unsigned int n, int flags[], int *res)
{
	int	precision;
	int	width;
	int	len;

	len = get_len_uint(n, 10);
	precision = flags[5];
	width = flags[6];
	if (flags[0] == 0 && flags[1] == 1 && flags[5] < 0)
		precision = width;
	precision = get_max(len, precision);
	if (n == 0 && flags[5] == 0)
		print_n_chars(width, ' ');
	else if (flags[0] == 0)
	{
		print_n_chars(width - precision, ' ');
		print_n_chars(precision - len, '0');
		print_uint(n);
	}
	else
	{
		print_n_chars(precision - len, '0');
		print_uint(n);
		print_n_chars(width - precision, ' ');
	}
	*res += get_max(precision, width);
}

void	print_arg(const char *fmt, int *res, va_list ap, int flags[])
{
	if (*fmt == 'i' || *fmt == 'd')
		print_d(va_arg(ap, int), flags, res);
	else if (*fmt == 'c')
		print_c((unsigned char)va_arg(ap, int), flags, res);
	else if (*fmt == 's')
		print_s(va_arg(ap, char *), flags, res);
	else if (*fmt == 'p')
		print_p(va_arg(ap, void *), flags, res);
	else if (*fmt == 'u')
		print_u(va_arg(ap, unsigned int), flags, res);
	else if (*fmt == 'x')
		print_x(va_arg(ap, unsigned int), flags, res);
	else if (*fmt == 'X')
		print_big_x(va_arg(ap, unsigned int), flags, res);
	else if (*fmt == '%')
	{
		write(1, "%", 1);
		*res += 1;
	}
}
