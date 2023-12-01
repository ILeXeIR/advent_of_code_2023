/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 15:41:38 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/17 15:18:33 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (res);
}

// int	main(void)
// {
// 	char	*s = "akadshfihads";

// 	printf("%s\n", ft_strrchr(s, 'd'));
// 	return (0);
// }
