/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 14:45:30 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/05 15:26:43 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c\n", ft_tolower('a'));
// 	printf("%c\n", ft_tolower('A'));
// 	printf("%c\n", ft_tolower('5'));
// 	printf("%c\n", ft_tolower('%'));
// 	printf("%c\n", ft_tolower('t'));
// 	printf("%c\n", ft_tolower('R'));
// 	printf("%c\n", ft_tolower('-'));
// 	printf("%c\n", ft_tolower(66));
// 	printf("%c\n", ft_tolower(100));
// 	return (0);
// }
