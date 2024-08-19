/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:05:19 by smercado          #+#    #+#             */
/*   Updated: 2024/07/01 14:28:19 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	i = 0;
	ss1 = (const unsigned char *) s1;
	ss2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return ((int)ss1[i] - (int)ss2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char *s1 = "atoms\0\0\0\0";
	char *s2 = "atoms\0abc";
	int ret = 0;
	ret = ft_memcmp(s1, s2, 8);

	printf("ret: %d\n", ret);
	return (0);

}*/
