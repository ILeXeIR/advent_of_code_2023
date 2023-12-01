/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:03:44 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/10 12:19:45 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("testfile.txt", O_RDWR | O_APPEND);
// 	ft_putchar_fd('A', fd);
// 	ft_putchar_fd('4', fd);
// 	ft_putchar_fd('\n', fd);
// 	close(fd);
// 	return (0);
// }
