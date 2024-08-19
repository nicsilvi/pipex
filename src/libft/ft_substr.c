/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:24:29 by smercado          #+#    #+#             */
/*   Updated: 2024/07/02 08:56:59 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* crea una subcadena desde el indice start hasta tamano len. 
copia y devuelve puntero a la subcadena o null si falla malloc. 
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		pos;
	size_t		len_s;

	pos = 0;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start <= len_s)
	{
		if (len > len_s - start)
			len = len_s - start;
		ptr = (char *)ft_calloc((len + 1), sizeof(char));
		if (!ptr)
			return (0);
		while (pos < len && s[start + pos] != '\0')
		{
			ptr[pos] = s[start + pos];
			pos++;
		}
	}
	else
		return (ft_calloc(1, sizeof(char)));
	return (ptr);
}
/*
#include <stdio.h>

int main()
{
    // Cadena de prueba
    const char *original = "test";
    size_t len = 1;
	char *ret = ft_substr(original, 10, len);

    if (ret)
    {
        printf("ret: %s\n", ret);
        free(ret);
    }
    else
    {
        printf("Failed to allocate memory for ret.\n");
    }
    return 0;
}*/
