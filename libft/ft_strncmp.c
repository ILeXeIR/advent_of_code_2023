/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:04:26 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/05 16:16:53 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char	*s1 = "Hello1";
// 	char	*s2 = "\200";
// 	int		x = 5;

// 	printf("%d\n", ft_strncmp(s1, s2, x));
// 	printf("%d\n", strncmp(s1, s2, x));
// 	return (0);
// }
