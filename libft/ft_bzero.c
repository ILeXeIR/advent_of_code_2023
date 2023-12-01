/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:24:45 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/04 16:33:12 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int	main(void)
// {
// 	char	str1[11] = "xxxxxxxxxx";
// 	char	str2[11] = "yyyyyyyyyy";

// 	ft_bzero(str1 + 2, 3);
// 	bzero(str2 + 2, 3);
// 	printf("%s\n", str1);
// 	printf("%s\n", str1 + 5);
// 	printf("%s\n", str2);
// 	printf("%s\n", str2 + 5);
// 	return (0);
// }
