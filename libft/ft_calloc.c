/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 16:45:42 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/19 15:07:45 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_mem;

	new_mem = malloc(nmemb * size);
	if (new_mem != NULL)
		ft_bzero(new_mem, nmemb * size);
	return (new_mem);
}

// int	main(void)
// {
// 	int	*array;

// 	array = (int *)malloc(0);
// 	if (array != NULL)
// 	{
// 		printf("%s\n", "success");
// 		free(array);
// 	}
// 	else
// 		printf("%s\n", "error");
// 	return (0);
// }
