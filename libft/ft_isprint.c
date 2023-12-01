/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:27:48 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/04 13:07:40 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (16384);
	return (0);
}

// int	main(void)
// {
// 	printf("%d ", ft_isprint('0'));
// 	printf("%d ", ft_isprint(0));
// 	printf("%d ", ft_isprint('a'));
// 	printf("%d ", ft_isprint('\n'));
// 	printf("%d ", ft_isprint(' '));
// 	printf("%d ", ft_isprint(233));
// 	printf("%d\n", ft_isprint(-53));
// 	printf("%d ", isprint('0'));
// 	printf("%d ", isprint(0));
// 	printf("%d ", isprint('a'));
// 	printf("%d ", isprint('\n'));
// 	printf("%d ", isprint(' '));
// 	printf("%d ", isprint(233));
// 	printf("%d\n", isprint(-53));
// 	return (0);
// }
