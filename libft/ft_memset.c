/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:35:49 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/06 18:17:24 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str1[11] = "xxxxxxxxxx";
// 	char	str2[11] = "yyyyyyyyyy";

// 	ft_memset(str1 + 2, 'A', 3);
// 	memset(str2 + 2, 'B', 3);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }
