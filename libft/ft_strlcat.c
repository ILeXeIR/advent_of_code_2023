/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 12:58:19 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/06 15:58:28 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
		i++;
	while (i + j + 1 < size && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

// int	main(void)
// {
// 	char	src[12] = "12345678";
// 	char	dst1[20] = "xxxxx";
// 	char	dst2[20] = "xxxxx";
// 	int		len1;
// 	int		len2;

// 	len1 = ft_strlcat(dst1, src, sizeof(dst1));
// 	len2 = strlcat(dst2, src, sizeof(dst2));
// 	printf("%d\n", len1);
// 	printf("%s\n\n", dst1);
// 	printf("%d\n", len2);
// 	printf("%s\n", dst2);
// 	return (0);
// }
