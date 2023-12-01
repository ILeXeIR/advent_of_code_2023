/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:21:03 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/04 14:27:44 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	printf("%zu ", ft_strlen("kjasdhf 123"));
// 	printf("%zu ", ft_strlen(""));
// 	printf("%zu\n", ft_strlen(" "));
// }
