/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:46:12 by smercado          #+#    #+#             */
/*   Updated: 2024/07/02 08:22:36 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* envia el string s al fd + un salto de linea
*/
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen((const char *)s));
	ft_putchar_fd('\n', fd);
}
