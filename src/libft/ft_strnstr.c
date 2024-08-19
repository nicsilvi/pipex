/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:18:45 by smercado          #+#    #+#             */
/*   Updated: 2024/06/20 16:31:55 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
busca la primera ocurrencia de little dentro de big, con la capacidad de 
buscar len numero de car'acteres de big.
return un puntero al inicio de la primera ocurrencia de little dentro de big;
Null si no lo encuentra o puntero al incio de big si little esta vacio.
*/
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
