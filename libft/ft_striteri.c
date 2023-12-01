/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:40:32 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/11 16:11:01 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, s + i);
		i++;
	}
}

// void	func_test(unsigned int n, char *s)
// {
// 	if (n % 2 == 1)
// 		*s = 'X';
// }

// int	main(void)
// {
// 	char	str[] = "abcdefg";

// 	ft_striteri(str, &func_test);
// 	printf("%s\n", str);
// 	return (0);
// }
