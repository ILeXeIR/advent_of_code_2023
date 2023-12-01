/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:45:53 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/09 15:49:09 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("testfile.txt", O_RDWR | O_APPEND);
// 	ft_putendl_fd("abcdef", fd);
// 	ft_putendl_fd("1234", fd);
// 	ft_putendl_fd("    X", fd);
// 	close(fd);
// 	return (0);
// }
