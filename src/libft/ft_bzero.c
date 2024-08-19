/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:38 by smercado          #+#    #+#             */
/*   Updated: 2024/06/28 11:59:52 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
llena la memoria de '\0's hasta n size
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char bff[10];
	ft_bzero(bff, 3);
	printf("%s\n", bff);
	return (0);
}*/
