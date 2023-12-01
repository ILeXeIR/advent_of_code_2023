/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 13:25:25 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/06 14:16:14 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j]
			&& big[i + j] != '\0' && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		if (big[i + j] == '\0' || i + j == len)
			return (NULL);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str = "maaabaaoxaaba";
// 	char	*to_find = "aaba";

// 	printf("%s\n", ft_strnstr(str, to_find, 20));
// 	printf("%s\n", strnstr(str, to_find, 20));
// 	return (0);
// }
