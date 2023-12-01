/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 16:06:51 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 14:46:39 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_end_line(char buffer[BUFFER_SIZE + 1])
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}

static void	change_buffer(char buffer[BUFFER_SIZE + 1], int n)
{
	int	i;

	i = 0;
	while (n + i <= BUFFER_SIZE && buffer[n + i] != '\0')
	{
		buffer[i] = buffer[n + i];
		i++;
	}
	n = n + i;
	while (i < n && buffer[i] != '\0')
		buffer[i++] = '\0';
}

static int	add_from_buffer(char **s, size_t n, char buffer[BUFFER_SIZE + 1])
{
	int		len;
	char	*ptr;

	if (*s == NULL)
	{
		*s = (char *)malloc(n + 1);
		if (*s == NULL)
			return (-1);
		ft_strlcpy(*s, buffer, n + 1);
	}
	else
	{
		len = ft_strlen(*s);
		ptr = *s;
		*s = (char *)malloc(len + n + 1);
		if (s == NULL)
		{
			free(ptr);
			return (-1);
		}
		ft_strlcpy(*s, ptr, len + 1);
		ft_strlcpy(*s + len, buffer, n + 1);
		free(ptr);
	}
	return (0);
}

static int	read_from_fd(int fd, char **next_line, char buffer[BUFFER_SIZE + 1])
{
	int	len;

	change_buffer(buffer, BUFFER_SIZE + 1);
	len = read(fd, buffer, BUFFER_SIZE);
	if (len < 0)
	{
		if (*next_line != NULL)
			free(*next_line);
		*next_line = NULL;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*next_line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || (int)BUFFER_SIZE <= 0)
		return (NULL);
	next_line = NULL;
	while (1)
	{
		i = find_end_line(buffer);
		if (buffer[0] != '\0')
			if (add_from_buffer(&next_line, i + 1, buffer) < 0)
				return (NULL);
		if (buffer[i] == '\n')
		{
			change_buffer(buffer, i + 1);
			break ;
		}
		else
			if (read_from_fd(fd, &next_line, buffer) <= 0)
				break ;
	}
	return (next_line);
}
