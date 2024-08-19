/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:13:14 by smercado          #+#    #+#             */
/*   Updated: 2024/08/19 16:41:05 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	set_nulls(&pipex);
	if (argc != 5)
		ft_perror_msg(&pipex, "error en los argumentos", 1, NULL);
	init_pipex(&pipex, argc, argv, envp);
	pipex.final_p1 = find_cm(&pipex, pipex.spl_p, pipex.cmds1, 0);
	pipex.final_p2 = find_cm(&pipex, pipex.spl_p, pipex.cmds2, 1);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		ft_perror_msg(&pipex, "error al crear el hijo", 1, NULL);
	else if (!pipex.pid1)
		first_child_process(pipex, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		ft_perror_msg(&pipex, "error al crear el segundo hijo", 1, NULL);
	else if (!pipex.pid2)
		second_child_process(pipex, envp);
	waitpid(pipex.pid1, NULL, -1);
	waitpid(pipex.pid2, NULL, -1);
	all_in_one(&pipex);
	exit (0);
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		ft_perror_msg(pipex, "no such file or directory: ", 1, argv[1]);
	pipex->outfile = open(argv[argc -1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex->outfile == -1)
		ft_perror_msg(pipex, "parse error near '\n'", 1, NULL);
	if (pipe(pipex->tube) == -1)
		ft_perror_msg(pipex, "error al crear el pipe", 1, NULL);
	if ((envp == NULL) || (*envp == NULL))
		ft_perror_msg(pipex, "error en envp", 1, NULL);
	pipex->all_paths = find_paths(envp);
	if (pipex->all_paths == NULL)
		ft_perror_msg(pipex, "error de PATH", 1, NULL);
	pipex->spl_p = ft_split(pipex->all_paths, ':');
	if ((argv[2][0] == '\0') || (argv[3][0] == '\0'))
		ft_perror_msg(pipex, "command not found: ", 127, NULL);
	pipex->cmds1 = ft_split(argv[2], ' ');
	pipex->cmds2 = ft_split(argv[3], ' ');
}

char	*find_paths(char **envp)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (NULL);
	return (envp[i] + 5);
}

void	all_in_one(t_pipex *pipex)
{
	close_pipes(pipex);
	parent_free(pipex);
	first_child_free(pipex);
	second_child_free(pipex);
	free(pipex->final_p1);
	free(pipex->final_p2);
}

void	set_nulls(t_pipex *pipex)
{
	pipex->final_p1 = NULL;
	pipex->final_p2 = NULL;
	pipex->cmds1 = NULL;
	pipex->cmds2 = NULL;
	pipex->spl_p = NULL;
	pipex->all_paths = NULL;
}
