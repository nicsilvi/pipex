/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:59 by smercado          #+#    #+#             */
/*   Updated: 2024/07/01 15:05:31 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*pt;

	i = 0;
	pt = (const unsigned char *)s;
	while (i < n)
	{
		if (pt[i] == (unsigned char)c)
			return ((void *)&pt[i]);
		i++;
	}
	return (NULL);
}
