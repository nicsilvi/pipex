/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:14:21 by smercado          #+#    #+#             */
/*   Updated: 2024/08/09 13:27:20 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "src/libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*all_paths;
	char	**spl_p;
	char	**cmds1;
	char	**cmds2;
	char	*final_p1;
	char	*final_p2;
}	t_pipex;

// free_clean_errors:
void	ft_perror_msg(t_pipex *pipex, char *msg, int code, char *str);
void	close_pipes(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	first_child_free(t_pipex *pipex);
void	second_child_free(t_pipex *pipex);
void	all_in_one(t_pipex *pipex);
void	set_nulls(t_pipex *pipex);

// main program:
int		main(int argc, char **argv, char **envp);
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
char	*find_paths(char **envp);

// subprocesos:
void	first_child_process(t_pipex pipex, char **envp);
char	*find_cm(t_pipex *pipex, char **splited_paths, char **cm, int flag);
void	second_child_process(t_pipex pipex, char **envp);

#endif
