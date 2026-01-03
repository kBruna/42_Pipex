/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:29:27 by buehara           #+#    #+#             */
/*   Updated: 2026/01/02 21:33:45 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	define_std_input(t_pipex *pipex, int count)
{
	if (count == 0 && pipex->limiter == NULL)
	{
		pipex->infile = open(pipex->arg_in, O_RDONLY);
		if (pipex->infile == -1 || dup2(pipex->infile, STD_IN) == -1)
			error_free(pipex);
		close(pipex->infile);
	}
	else
	{
		if (dup2(pipex->oldfd, STD_IN) == -1)
			error_free(pipex);
	}
}

void	define_std_output(t_pipex *pipex, int count)
{
	if (count < pipex->headlst.lst_size - 1)
	{
		if (dup2(pipex->fd[1], STD_OUT) == -1)
			error_free(pipex);
	}
	else
	{
		pipex->outfile = open(pipex->arg_out, pipex->permission, 0644);
		if (pipex->outfile == -1 || dup2(pipex->outfile, STD_OUT) == -1)
			error_free(pipex);
		close(pipex->outfile);
	}
}

void	execve_run(t_pipex *pipex, t_list cmdlst, char **envp)
{
	char	*path;

	path = create_path(pipex->path_join, cmdlst.content, pipex);
	if (!path)
	{
		free_path(pipex->path_join);
		ft_lstclear(&pipex->headlst.list, free_path);
		if (pipex->limiter)
			free(pipex->limiter);
		perror("Command Not Found");
		exit(ERROR);
	}
	execve(path, cmdlst.content, envp);
	error_free(pipex);
}

void	child_process(t_pipex *pipex, int count, char **envp, t_list cmdlst)
{
	define_std_input(pipex, count);
	define_std_output(pipex, count);
	ft_close(pipex->oldfd, pipex->fd[1], pipex->fd[0], NO_FD);
	execve_run(pipex, cmdlst, envp);
}
