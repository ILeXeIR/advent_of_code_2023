/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:35:31 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/12 18:28:19 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;

	str = s;
	ch = c;
	while (n > 0 && *str != ch)
	{
		str++;
		n--;
	}
	if (n > 0 && *str == ch)
		return ((void *)str);
	return (NULL);
}

// int	main(void)
// {
// 	char	*s = "akadshf\200ihadsD";

// 	printf("%s\n", (char *)ft_memchr(s, 'f', 50));
// 	return (0);
// }
