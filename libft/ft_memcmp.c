/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:59:41 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/06 13:20:39 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	char	*s1 = "as1j\0iEj";
// 	char	*s2 = "as1j\0iej";
// 	// int	s1[] = {2, 4, 5, 1};
// 	// int	s2[] = {2, 4, 5, 754};

// 	printf("%d\n", ft_memcmp(s1, s2, 6));
// 	printf("%d\n", memcmp(s1, s2, 6));
// 	return (0);
// }
