/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:24:51 by smercado          #+#    #+#             */
/*   Updated: 2024/07/01 14:44:01 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*copia n bytes de src en dest y grantiza qe no se solapen (no como memcpy).
return > puntero a dest.
src y dest son posiciones de memoria, hay que ver cual esta delante 
para superponer de manera segura.
(src y dest pueden ser la misma variable+n para mover una palabra sobre otra).

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*s;

	temp = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (temp < s)
		while (n--)
			*temp++ = *s++;
	else
	{
		temp += (n - 1);
		s += (n - 1);
		while (n--)
			*temp-- = *s--;
	}
	return (dest);
}
/*
int	main(void)
{
	char dest[13];
	char *src = "rem ipssum dolor sit a";
	char *ret;

	ret = ft_memmove(dest, src, 10);
	printf("%s\n", ret);
	return (0);
}*/
