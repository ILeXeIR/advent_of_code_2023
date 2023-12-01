/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 15:44:05 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/13 19:47:01 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while ('0' <= *nptr && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}

// int	main(void)
// {
// 	printf("%d\n", atoi("422147400000033"));
// 	printf("%d\n\n", ft_atoi("422147400000033"));
// 	printf("%d\n", atoi(""));
// 	printf("%d\n\n", ft_atoi(""));
// 	printf("%d\n", atoi("a0000124"));
// 	printf("%d\n\n", ft_atoi("a0000124"));
// 	printf("%d\n", atoi("0000125abc"));
// 	printf("%d\n\n", ft_atoi("0000125abc"));
// 	printf("%d\n", atoi("-0000126"));
// 	printf("%d\n\n", ft_atoi("-0000126"));
// 	printf("%d\n", atoi("+0000127"));
// 	printf("%d\n\n", ft_atoi("+0000127"));
// 	printf("%d\n", atoi("-+0000128"));
// 	printf("%d\n\n", ft_atoi("-+0000128"));
// 	printf("%d\n", atoi("+-0000129"));
// 	printf("%d\n\n", ft_atoi("+-0000129"));
// 	printf("%d\n", atoi("\n+0000130"));
// 	printf("%d\n\n", ft_atoi("\n+0000130"));
// 	printf("%d\n", atoi("     -0000131"));
// 	printf("%d\n\n", ft_atoi("     -0000131"));
// 	return (0);
// }
