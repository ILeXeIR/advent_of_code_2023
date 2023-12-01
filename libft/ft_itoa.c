/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 12:46:08 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/10 12:19:07 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n /= -10;
		len = 2;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	numtostr(char *res, int n, size_t len)
{
	res[len] = '\0';
	if (n < 0)
	{
		*res = '-';
		res[len - 1] = -(n % 10) + '0';
		n /= -10;
		len -= 2;
		res++;
	}
	while (len-- > 0)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = get_len(n);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	numtostr(res, n, len);
	return (res);
}

// int	main(void)
// {
// 	char	*res;
// 	int		n = -10000;

// 	res = ft_itoa(n);
// 	printf("%s\n", res);
// 	if (res != NULL)
// 		free(res);
// 	return (0);
// }
