/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 10:32:27 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/09 11:09:07 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}

// int	main(void)
// {
// 	char	*s1 = "12345";
// 	char	*s2 = "abcde";
// 	char	*new_str;

// 	new_str = ft_strjoin(s1, s2);
// 	printf("%s\n", new_str);
// 	if (new_str != NULL)
// 		free(new_str);
// 	return (0);
// }
