/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alpetukh <alpetukh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 19:47:09 by alpetukh      #+#    #+#                 */
/*   Updated: 2023/10/17 20:12:00 by alpetukh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*node;

	first_node = ft_lstnew((*f)(lst->content));
	if (first_node == NULL)
		return (NULL);
	node = first_node;
	while (lst->next != NULL)
	{
		lst = lst->next;
		node->next = ft_lstnew((*f)(lst->content));
		if (node->next == NULL)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		node = node->next;
	}
	return (first_node);
}
