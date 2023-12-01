/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 17:52:26 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/10 14:40:32 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1024);
	return (0);
}

// int	main(void)
// {
// 	printf("%d ", ft_isalpha(64));
// 	printf("%d ", ft_isalpha(65));
// 	printf("%d ", ft_isalpha('3'));
// 	printf("%d ", ft_isalpha('Z'));
// 	printf("%d ", ft_isalpha('-'));
// 	printf("%d ", ft_isalpha('\n'));
// 	printf("%d\n", ft_isalpha('a'));
// 	printf("%d ", isalpha(64));
// 	printf("%d ", isalpha(65));
// 	printf("%d ", isalpha('3'));
// 	printf("%d ", isalpha('Z'));
// 	printf("%d ", isalpha('-'));
// 	printf("%d ", isalpha('\n'));
// 	printf("%d\n", isalpha('a'));
// 	return (0);
// }
