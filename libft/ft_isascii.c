/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:27:30 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/04 14:35:17 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d ", ft_isascii('0'));
// 	printf("%d ", ft_isascii(0));
// 	printf("%d ", ft_isascii('a'));
// 	printf("%d ", ft_isascii('\n'));
// 	printf("%d ", ft_isascii(' '));
// 	printf("%d ", ft_isascii(127));
// 	printf("%d\n", ft_isascii(128));
// 	printf("%d ", isascii('0'));
// 	printf("%d ", isascii(0));
// 	printf("%d ", isascii('a'));
// 	printf("%d ", isascii('\n'));
// 	printf("%d ", isascii(' '));
// 	printf("%d ", isascii(127));
// 	printf("%d\n", isascii(128));
// 	return (0);
// }
