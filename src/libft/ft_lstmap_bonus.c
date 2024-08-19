/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:00:39 by smercado          #+#    #+#             */
/*   Updated: 2024/06/28 14:38:38 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * itera en lst y aplica *f, crea una lista nueva con el resultado. 
 *
 *return: nueva lista o null si falla malloc.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*newlst;
	t_list	*newnodo;
	void	*result;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		result = f(lst->content);
		newnodo = ft_lstnew(result);
		if (!newnodo)
		{
			del(result);
			ft_lstclear(&newlst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnodo);
		lst = lst->next;
	}
	return (newlst);
}
