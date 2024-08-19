/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:54:37 by smercado          #+#    #+#             */
/*   Updated: 2024/07/01 10:47:39 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/* concatena cadenas y garantiza que no se escriba fuera del limite
del bufer. la cadena siempre tienq que acabar en nulo. 
src se concatena en dest, dest debe ser lo suficientemente grande (size). 
return> devuelve el tam que intento crear (src + dest);
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	index;

	dlen = 0;
	slen = 0;
	index = 0;
	while (dlen < size && dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (size - dlen < 1)
		return (dlen + slen);
	while (index < slen && dlen + index < size - 1)
	{
		dst[dlen + index] = src[index];
		index++;
	}
	dst[dlen + index] = '\0';
	return (dlen + slen);
}
/*
int	main(void)
{
	unsigned int res;
	char dest[15];

	ft_memset(dest, 'r', 10);
	dest[15] = '\0';
	res = ft_strlcat(dest, "1234", 6);
	printf("%s", dest);
	printf("%u", res);
	return (0);
}*/
