/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:18:26 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/09 14:38:48 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// char	func_test(unsigned int n, char c)
// {
// 	if (n < 5)
// 		return (c);
// 	return ('0');
// }

// int	main(void)
// {
// 	char	*str = "abcdefg";
// 	char	*res;

// 	res = ft_strmapi(str, &func_test);
// 	if (res == NULL)
// 		return (1);
// 	printf("%s\n", res);
// 	free(res);
// 	return (0);
// }
