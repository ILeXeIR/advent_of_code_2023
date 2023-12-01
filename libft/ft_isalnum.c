/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:27:15 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/04 12:51:07 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	return (0);
}

// int	main(void)
// {
// 	printf("%d ", ft_isalnum('0'));
// 	printf("%d ", ft_isalnum(0));
// 	printf("%d ", ft_isalnum('a'));
// 	printf("%d\n", ft_isalnum(53));
// 	printf("%d ", isalnum('0'));
// 	printf("%d ", isalnum(0));
// 	printf("%d ", isalnum('a'));
// 	printf("%d\n", isalnum(53));
// 	return (0);
// }
