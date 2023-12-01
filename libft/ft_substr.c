/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 18:47:24 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/17 16:08:05 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	while (*s != '\0' && start > 0)
	{
		s++;
		start--;
	}
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, len + 1);
	return (new_str);
}

// int	main(void)
// {
// 	char	str[] = "adgdsag";
// 	char	*dst;

// 	dst = ft_substr(str, 3, 10);
// 	printf("%s\n", dst);
// 	if (dst != NULL)
// 		free(dst);
// 	return (0);
// }
