/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:53:46 by smercado          #+#    #+#             */
/*   Updated: 2024/07/01 10:46:54 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
separa S en un array de strings. cada palabra se delimita con c
devuelve el **array o null si malloc falla
el array debe acabar en NULL.


static int	ft_rs(char const*s, char c, int index)
{
	int	count;

	count = 0;
	while ((s[index] != c) && (s[index] != '\0'))
	{
		count++;
		index++;
	}
	return (count);
}
*/

static void	ft_freearray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	actualword;

	i = 0;
	words = 0;
	actualword = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !actualword)
		{
			actualword = 1;
			words++;
		}
		else if (s[i] == c)
			actualword = 0;
		i++;
	}
	return (words);
}

static char	*ft_makecpyarray(char const *s, int lettercounter, int start)
{
	char	*array;
	int		i;

	i = 0;
	array = (char *)malloc(sizeof(char) * (lettercounter + 1));
	if (!array)
		return (NULL);
	while (i < lettercounter)
	{
		array[i] = s[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

static char	**ft_makearray(char const *s, char c, char **array)
{
	int	i;
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (k < ft_count_words(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		i = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		array[k] = ft_makecpyarray(s, (j - i), i);
		if (!array[k])
		{
			ft_freearray(array);
			return (NULL);
		}
		k++;
	}
	array[k] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = ft_makearray(s, c, array);
	return (array);
}
/*
int main()
 {
     // Cadena de prueba
     char *s1 = "holacqueectalscesta";
    char **array;
    int i = 0;

     array = ft_split(s1, 'c');

     // Imprimir el resultado
     if (array)
     {
       while (array[i])
       {
         printf("string: %s\n", array[i]);
         free(array[i]);
         i++;
        }
     free(array);
     }
     else
     {
         printf("Fail.\n");
     }
     return (0);
 }*/
