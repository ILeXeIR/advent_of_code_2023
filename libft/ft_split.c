/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 11:21:03 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/11/21 20:23:08 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_array_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			len++;
		while (*s && *s != c)
			s++;
	}
	return (len);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	check_allocation(char **array, size_t len)
{
	size_t	i;

	if (array[len] != NULL)
		return (0);
	i = 0;
	while (i < len)
		free(array[i++]);
	free(array);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	word_len;
	size_t	arr_len;

	arr_len = get_array_length(s, c);
	if (arr_len == 0)
		return (NULL);
	res = (char **)malloc((arr_len + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[arr_len] = NULL;
	i = 0;
	while (i < arr_len)
	{
		while (*s == c)
			s++;
		word_len = get_word_len(s, c);
		res[i] = (char *)malloc(word_len + 1);
		if (check_allocation(res, i))
			return (NULL);
		ft_strlcpy(res[i++], s, word_len + 1);
		s += word_len;
	}
	return (res);
}

// int	main(void)
// {
// 	char	**result;
// 	int		i;

// 	result = ft_split("111adkh1df11akdh1aksd1fj123afkj44211", '1');
// 	i = 0;
// 	while (result[i] != 0)
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
