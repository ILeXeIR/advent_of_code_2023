/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 11:34:20 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/05 16:10:25 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	src[12] = "1234567";
// 	char	dst1[] = "xxxxxxxxxxxx";
// 	char	dst2[] = "xxxxxxxxxxxx";
// 	int		len1;
// 	int		len2;

// 	len1 = ft_strlcpy(dst1, src, sizeof(dst1));
// 	len2 = strlcpy(dst2, src, sizeof(dst2));
// 	printf("%d\n", len1);
// 	printf("%s\n\n", dst1);
// 	printf("%d\n", len2);
// 	printf("%s\n", dst2);
// 	return (0);
// }
