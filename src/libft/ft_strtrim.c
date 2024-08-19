/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:40:44 by smercado          #+#    #+#             */
/*   Updated: 2024/07/02 08:56:06 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* elimina en s1 los caracteres encontrados en set: 
recorre desde el inicio y desde el final hasta que encuentra algo que no es set. 
 devuelve la string resultante con una reserva de malloc. 
 ej> "abababMy name is Simonbababab" set: ab = "my name is Simon"
*/

static int	ft_trueinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;
	int		len;

	start = 0;
	len = 0;
	end = ft_strlen(s1) - 1;
	if (!s1)
	{
		new = ft_strdup("");
		return (new);
	}
	while (ft_trueinset(set, s1[start]))
		start++;
	while (ft_trueinset(set, s1[end]))
		end--;
	if (end <= 0)
	{
		new = ft_strdup("");
		return (new);
	}
	len = ((ft_strlen(s1) - start) - (ft_strlen(s1) - end) + 1);
	new = ft_substr(s1, start, len);
	return (new);
}
/*
int main()
 {
     // Cadena de prueba
     const char *s1 = "  \t \t \n   \n\n\n\t";
     const char *set = " \n\t";

     char *str = ft_strtrim(s1, set);

     // Imprimir el resultado
	 if (str)
     {
         printf("string: %s\n", str);
         free(str);  // Liberar memoria asignada
     }
     else
     {
         printf("Fail.\n");
     }

     return 0;
 }*/
