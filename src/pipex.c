/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:14:06 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 21:16:05 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_dup(int fd, int infile, int outfile, char **path_join)
{
	if (dup2(infile, STD_IN) == -1)
	{
		close(infile);
		error_free(path_join, infile, outfile);
	}
	if (dup2(fd, STD_OUT) == -1)
	{
		close(fd);
		close(infile);
		error_free(path_join, infile, outfile);
	}
}

void	first_child(t_pipex pipex, char **envp, char **argv)
{
	char	*path;

	path = NULL;
	pipex.pid[0] = fork();
	if (pipex.pid[0] == -1)
		error_free(pipex.path_join, pipex.infile, pipex.outfile);
	if (pipex.pid[0] == 0)
	{
		if (pipex.infile == -1)
			exit(ERROR);
		pipe_dup(pipex.fd[1], pipex.infile, pipex.outfile, pipex.path_join);
		ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
		pipex.cmd = ft_split(argv[2], ' ');
		path = find_path(pipex.path_join, pipex.cmd);
		execve(path, pipex.cmd, envp);
		free(path);
		free(pipex.cmd);
		free(pipex.path_join);
		exit(126);
	}
	close(pipex.fd[1]);
}

void	second_child(t_pipex pipex, char **envp, char **argv)
{
	char	*path;

	path = NULL;
	pipex.pid[1] = fork();
	if (pipex.pid[1] == -1)
		error_free(pipex.path_join, pipex.infile, pipex.outfile);
	if (pipex.pid[1] == 0)
	{
		if (pipex.outfile == -1)
			exit(ERROR);
		pipe_dup(pipex.outfile, pipex.fd[0], pipex.infile, pipex.path_join);
		ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
		pipex.cmd = ft_split(argv[3], ' ');
		path = find_path(pipex.path_join, pipex.cmd);
		execve(path, pipex.cmd, envp);
		free(path);
		free(pipex.cmd);
		free(pipex.path_join);
		exit(126);
	}
}
