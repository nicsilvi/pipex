/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:18:50 by smercado          #+#    #+#             */
/*   Updated: 2024/06/28 11:54:58 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*busco en lo que apunta const char *s, el caracter c pasado como int.
return un puntero al primer caracter que coincida o NULL si no se encuentra.

*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && ((char)c != s[i]))
		i++;
	if ((char)c == s[i])
		return ((char *) &s[i]);
	return (NULL);
}
/*
se podria hacer usando ft_memchr:
const char *ft_strchr(const char *pStr, char value)
{
	return (const char *)ft_memchr(pStr, value, ft_strlen(pStr)+1)
	//el +1 es necesario pq strchr puede buscar el null termination
} */
