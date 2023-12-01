/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:51:33 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/09 16:15:20 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	ch;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n < -9)
			ft_putnbr_fd(-(n / 10), fd);
		ft_putnbr_fd(-(n % 10), fd);
	}
	else if (n < 10)
	{
		ch = n + '0';
		write(fd, &ch, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("testfile.txt", O_RDWR | O_APPEND);
// 	ft_putnbr_fd(-13000, 1);
// 	close(fd);
// 	return (0);
// }
