/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 17:02:48 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/10 12:20:16 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_direction(void *dest, const void *src, size_t n, int *sign)
{
	if (src == dest || n == 0)
		*sign = 0;
	else if (src > dest)
		*sign = 1;
	else
	{
		*sign = -1;
		return (n - 1);
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*from_str;
	unsigned char		*to_str;
	int					i;
	int					sign;

	i = get_direction(dest, src, n, &sign);
	if (sign == 0)
		return (dest);
	from_str = src;
	to_str = dest;
	while (n > 0)
	{
		to_str[i] = from_str[i];
		i += sign;
		n--;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str1[11] = "1234567890";
// 	char	str2[11] = "1234567890";

// 	ft_memmove(str1 + 3, str1, 5);
// 	memmove(str2 + 3, str2, 5);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }
