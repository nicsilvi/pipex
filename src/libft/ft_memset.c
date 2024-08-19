/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:25:20 by smercado          #+#    #+#             */
/*   Updated: 2024/06/17 13:24:22 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/* 
se llena n veces la memoria apuntada en VOID *s 
con el valor especificado en c.
int c tiene que convertiser a unsigned char para llenar el bloque de memoria.
no es void, es void *, por lo que devuelve un puntero a la memoria s 
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char *)s;
	while (i < n)
	{
		pt[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char buff[10];
	ft_memset(buff, 'A', 10);
	printf("buff after memset is %s\n", buff);
	return (0);
}*/
