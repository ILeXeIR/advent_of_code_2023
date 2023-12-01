/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:33:30 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/09 12:24:48 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*from_str;
	unsigned char		*to_str;
	size_t				i;

	from_str = src;
	to_str = dest;
	i = 0;
	while (i < n)
	{
		to_str[i] = from_str[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str1[11] = "asdfghjkl;";
// 	char	str2[11] = "1234567890";

// 	ft_memcpy(str1 + 5, str2, 3);
// 	memcpy(str2 + 5, str1, 3);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }
