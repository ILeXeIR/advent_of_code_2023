/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 10:48:54 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/10 12:22:18 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	len;

	while (is_in_set(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && is_in_set(s1[len - 1], set))
		len--;
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, len + 1);
	return (new_str);
}

// int	main(void)
// {
// 	char	*s1 = "31231aba123cd12111";
// 	char	*set = "123";
// 	char	*new_str;

// 	new_str = ft_strtrim(s1, set);
// 	printf("%s\n", new_str);
// 	if (new_str != NULL)
// 		free(new_str);
// 	return (0);
// }
