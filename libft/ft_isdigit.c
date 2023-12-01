/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:26:51 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/04 12:36:58 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (2048);
	return (0);
}

// int	main(void)
// {
// 	printf("%d ", ft_isdigit('0'));
// 	printf("%d ", ft_isdigit(0));
// 	printf("%d ", ft_isdigit('a'));
// 	printf("%d\n", ft_isdigit(53));
// 	printf("%d ", isdigit('0'));
// 	printf("%d ", isdigit(0));
// 	printf("%d ", isdigit('a'));
// 	printf("%d\n", isdigit(53));
// 	return (0);
// }
