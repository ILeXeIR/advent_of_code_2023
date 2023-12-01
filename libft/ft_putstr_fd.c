/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:38:09 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/09 15:44:50 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("testfile.txt", O_RDWR | O_APPEND);
// 	ft_putstr_fd("abcdef ", fd);
// 	ft_putstr_fd("1234\n", 1);
// 	ft_putstr_fd("    X    ", fd);
// 	close(fd);
// 	return (0);
// }
