/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clean_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:20:22 by smercado          #+#    #+#             */
/*   Updated: 2024/08/09 12:49:02 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror_msg(t_pipex *pipex, char *msg, int code, char *str)
{
	write(STDERR_FILENO, "zsh: ", 5);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	if (pipex->cmds1)
		first_child_free(pipex);
	if (pipex->cmds2)
		second_child_free(pipex);
	exit(code);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
	close(pipex->infile);
	close(pipex->outfile);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->spl_p[i])
	{
		free(pipex->spl_p[i]);
		i++;
	}
	free(pipex->spl_p);
}

void	first_child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmds1[i])
	{
		free(pipex->cmds1[i]);
		i++;
	}
	free(pipex->cmds1);
}

void	second_child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmds2[i])
	{
		free(pipex->cmds2[i]);
		i++;
	}
	free(pipex->cmds2);
}
