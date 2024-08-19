/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:58:54 by smercado          #+#    #+#             */
/*   Updated: 2024/06/28 12:01:03 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* limpia de nodos la t_list utilizndo la función del. 
 *al eliminar el nodo actual borramos también la referencia
 al siguiente, por eso se utiliza una variable temporal
 *
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	if (!(*lst) || !del || !lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
