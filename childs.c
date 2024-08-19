/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:13:02 by smercado          #+#    #+#             */
/*   Updated: 2024/08/09 12:54:29 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_process(t_pipex pipex, char **envp)
{
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		ft_perror_msg(&pipex, "error al cambiar la lectura al infile", 1, NULL);
	if (dup2(pipex.tube[1], STDOUT_FILENO) == -1)
		ft_perror_msg(&pipex, "error al pasar la escritura al tube", 1, NULL);
	close_pipes(&pipex);
	if (!pipex.final_p1)
	{
		parent_free(&pipex);
		ft_perror_msg(&pipex, "command not found", 1, NULL);
	}
	execve(pipex.final_p1, pipex.cmds1, envp);
	ft_perror_msg(&pipex, "error en exceve", 1, NULL);
}

void	second_child_process(t_pipex pipex, char **envp)
{
	if (dup2(pipex.tube[0], STDIN_FILENO) == -1)
		ft_perror_msg(&pipex, "error tube[0]", 1, NULL);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		ft_perror_msg(&pipex, "error write outfile", 1, NULL);
	close_pipes(&pipex);
	if (pipex.infile < 0)
		exit(1);
	if (!pipex.final_p2)
	{
		parent_free(&pipex);
		free(pipex.final_p1);
		ft_perror_msg(&pipex, "comand not found", 127, NULL);
	}
	execve(pipex.final_p2, pipex.cmds2, envp);
	ft_perror_msg(&pipex, "error en exceve2", 1, NULL);
}

char	*find_cm(t_pipex *pipex, char **spl_p, char **cm, int flag)
{
	char	*temp;
	char	*cmdfinal;
	int		i;

	i = 0;
	if (!spl_p)
		return (ft_perror_msg(pipex, "no existe paths", 1, NULL), NULL);
	while (spl_p[i])
	{
		temp = ft_strjoin(spl_p[i], "/");
		cmdfinal = ft_strjoin(temp, cm[0]);
		free(temp);
		if (access(cmdfinal, X_OK) == 0)
			return (cmdfinal);
		free(cmdfinal);
		i++;
	}
	parent_free(pipex);
	close_pipes(pipex);
	if (flag)
		free(pipex->final_p1);
	return (ft_perror_msg(pipex, "comand not found: ", 127, cm[0]), NULL);
}
