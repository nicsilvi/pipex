/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:45:28 by smercado          #+#    #+#             */
/*   Updated: 2024/07/01 11:35:19 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_notpositive(int n, int *is_negative, int *is_intmin)
{
	if (n == -2147483648)
	{
		n = 147483648;
		*is_negative = 1;
		*is_intmin = 1;
	}
	else
	{
		*is_negative = 1;
		n = n * -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		is_negative;
	int		is_intmin;

	i = ft_intlen(n);
	is_negative = 0;
	is_intmin = 0;
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		n = ft_notpositive(n, &is_negative, &is_intmin);
	while ((i - 1) >= 0)
	{
		str[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (is_negative)
		str[0] = '-';
	if (is_intmin)
		str[1] = '2';
	return (str);
}
