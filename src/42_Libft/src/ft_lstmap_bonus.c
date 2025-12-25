/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:34:13 by buehara           #+#    #+#             */
/*   Updated: 2025/10/06 20:17:44 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	**head;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = &result;
	while (lst != NULL)
	{
		*head = ft_lstnew(f(lst->content));
		if (!*head)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		head = &(*head)->next;
		lst = lst->next;
	}
	return (result);
}
