/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:51:34 by smercado          #+#    #+#             */
/*   Updated: 2024/07/02 08:23:34 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*snew;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	snew = (char *)malloc(sizeof(char) * (len + 1));
	if (!snew)
		return (NULL);
	while (s[i] != '\0')
	{
		snew[i] = s[i];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
/* 
#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(const char *s);

int main(void)
{
    char *original = "Hello, World!";
    char *duplicate;

    duplicate = ft_strdup(original);
    if (duplicate == NULL) {
        printf("Error: ft_strdup devolvió NULL\n");
        return 1;
    }

    printf("Cadena original: %s\n", original);
    printf("Cadena duplicada: %s\n", duplicate);

    // Liberar la memoria asignada
    free(duplicate);

    return 0;
}
size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return len;
}*/
