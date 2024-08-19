/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:47:39 by smercado          #+#    #+#             */
/*   Updated: 2024/06/28 11:54:38 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
copia de src a dest hasta max number de size dejando 
espacio para el '\0' de dest. (size -1)
return: el total de src. 

si la cadena a copiar es mas larga qe el destino, se copia hasta n -1. 
si size es 0 o menor, no se hace nada y se devuleve el tamano de src. 
*/
#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	tam;
	unsigned int	i;

	i = 0;
	tam = 0;
	while (src[tam] != '\0')
		tam++;
	if (size < 1)
		return (tam);
	while (src[i] != '\0' && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (tam);
}
/*
int	main(void)
{
	char dest[10];
	char *src = "holaque tal la vida";
	char *ret;

	ft_strlcpy(dest, src, 5);
	printf("%s\n", dest);
	return (0);
}*/
