/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 18:26:04 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/16 13:48:05 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*new_str;
	int		len;

	len = ft_strlen(s);
	new_str = malloc(len + 1);
	if (new_str != NULL)
		ft_strlcpy(new_str, s, len + 1);
	return (new_str);
}

// int	main(void)
// {
// 	char	str[] = "adgdsag";
// 	char	*dst1 = "xxxx";
// 	char	*dst2 = "xxxx";

// 	dst1 = ft_strdup(str);
// 	dst2 = strdup(str);
// 	printf("%s\n", dst1);
// 	printf("%s\n", dst2);
// 	free(dst1);
// 	free(dst2);
// 	return (0);
// }
