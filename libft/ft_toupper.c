/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 14:45:37 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/05 15:06:46 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c\n", ft_toupper('a'));
// 	printf("%c\n", ft_toupper('A'));
// 	printf("%c\n", ft_toupper('5'));
// 	printf("%c\n", ft_toupper('%'));
// 	printf("%c\n", ft_toupper('t'));
// 	printf("%c\n", ft_toupper('R'));
// 	printf("%c\n", ft_toupper('-'));
// 	printf("%c\n", ft_toupper(66));
// 	printf("%c\n", ft_toupper(100));
// 	return (0);
// }
