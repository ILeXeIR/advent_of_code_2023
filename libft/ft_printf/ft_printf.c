/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 12:49:29 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 15:09:23 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Order of flags:
	"-0+ #."
	 012345 - indexes
	 6 - minimum width

	c "-6"
	s ".-6"
	p "-6"
	d ".-0+ 6"
	i ".-0+ 6"
	u ".-06"
	x ".-0#6"
	X ".-0#6"
	% ""

*/

int		get_num(const char *fmt, int *n);
void	print_arg(const char *fmt, int *res, va_list ap, int flags[]);

static void	set_flag(int flags[], char c, int i)
{
	if (c == '-')
		flags[0] = i;
	else if (c == '0')
		flags[1] = i;
	else if (c == '+')
		flags[2] = i;
	else if (c == ' ')
		flags[3] = i;
	else if (c == '#')
		flags[4] = i;
	else if (c == '.')
		flags[5] = i;
	else if (c == 'w')
		flags[6] = i;
}

static int	is_conversion(char c)
{
	const char	*str = "cspdiuxX%";

	while (*str != 0)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	recognize_format(const char *fmt, va_list ap, int *res)
{
	int	n;
	int	flags[7];

	n = 1;
	ft_bzero(flags, sizeof(int) * 7);
	while (fmt[n] == '-' || fmt[n] == '0' || fmt[n] == '+'
		|| fmt[n] == ' ' || fmt[n] == '#')
		set_flag(flags, fmt[n++], 1);
	if ('1' <= fmt[n] && fmt[n] <= '9')
		set_flag(flags, 'w', get_num(fmt, &n));
	if (fmt[n] == '.')
	{
		n++;
		set_flag(flags, '.', get_num(fmt, &n));
	}
	else
		set_flag(flags, '.', -1);
	if (is_conversion(fmt[n]) == 1)
	{
		print_arg(fmt + n, res, ap, flags);
		return (n + 1);
	}
	write(1, "%", 1);
	*res += 1;
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;
	int		res;

	va_start(ap, fmt);
	if (fmt == NULL)
		return (-1);
	res = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			write(1, fmt++, 1);
			res++;
		}
		else
		{
			n = recognize_format(fmt, ap, &res);
			fmt += n;
		}
	}
	va_end(ap);
	return (res);
}
