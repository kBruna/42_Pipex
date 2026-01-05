/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:14:06 by buehara           #+#    #+#             */
/*   Updated: 2026/01/05 18:49:26 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_dup(int fd, int infile, int outfile, char **path_join)
{
	if (dup2(infile, STD_IN) == -1)
	{
		close(infile);
		error_free(path_join, infile, outfile, "Error");
	}
	if (dup2(fd, STD_OUT) == -1)
	{
		close(fd);
		close(infile);
		error_free(path_join, infile, outfile, "Error");
	}
}

void	first_child(t_pipex pipex, char **envp, char **argv)
{
	char	*path;

	path = NULL;
	pipex.pid[0] = fork();
	if (pipex.pid[0] == -1)
		error_free(pipex.path_join, pipex.infile, pipex.outfile, "Fork");
	if (pipex.pid[0] == 0)
	{
		if (pipex.infile == -1)
			error_file(pipex);
		pipe_dup(pipex.fd[1], pipex.infile, pipex.outfile, pipex.path_join);
		ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
		pipex.cmd = ft_split(argv[2], ' ');
		if (!pipex.cmd || !pipex.cmd[0])
			error_path(pipex.path_join, pipex.cmd, 127, "Command Error");
		path = find_path(pipex.path_join, pipex.cmd);
		if (!path)
			error_path(pipex.path_join, pipex.cmd, 127, "Command Error");
		execve(path, pipex.cmd, envp);
		free(path);
		error_path(pipex.path_join, pipex.cmd, 126, "Command Error");
	}
}

void	second_child(t_pipex pipex, char **envp, char **argv)
{
	char	*path;

	path = NULL;
	pipex.pid[1] = fork();
	if (pipex.pid[1] == -1)
		error_free(pipex.path_join, pipex.infile, pipex.outfile, "Fork");
	if (pipex.pid[1] == 0)
	{
		if (pipex.outfile == -1)
			error_file(pipex);
		pipe_dup(pipex.outfile, pipex.fd[0], pipex.infile, pipex.path_join);
		ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
		pipex.cmd = ft_split(argv[3], ' ');
		if (!pipex.cmd || !pipex.cmd[0])
			error_path(pipex.path_join, pipex.cmd, 127, "Command Error");
		path = find_path(pipex.path_join, pipex.cmd);
		if (!path)
			error_path(pipex.path_join, pipex.cmd, 127, "Command Error");
		execve(path, pipex.cmd, envp);
		free(path);
		error_path(pipex.path_join, pipex.cmd, 126, "Command Error");
	}
}

void	error_path(char **path_join, char **cmd, int err, char *msg_err)
{
	free_path(path_join);
	free_path(cmd);
	perror(msg_err);
	exit(err);
}
