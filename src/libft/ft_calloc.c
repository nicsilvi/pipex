/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:36:37 by smercado          #+#    #+#             */
/*   Updated: 2024/06/20 13:41:23 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((size * nmemb) / nmemb != size)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}
/*
int	main(void)
{
	size_t	i = 0;
	size_t nmemb = 10;
	size_t size = sizeof(int);

	int *arr = (int *)ft_calloc(nmemb, size);
	if (arr == NULL)
	{
		printf("Error\n");
		return (-1);
	}
	printf("valores arrar:\n");
	while (i++ < nmemb)
		printf("arr[%zu] = %d\n", 1, arr[i]);
	free(arr);
	return (0);
}*/
