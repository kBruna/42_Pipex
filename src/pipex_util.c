/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:42:24 by buehara           #+#    #+#             */
/*   Updated: 2026/01/01 21:03:24 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_path(void *split)
{
	int		index;
	char	**temp;

	if (!split)
		return ;	
	index = 0;
	temp = (char **)split;
	while (temp[index] != NULL)
	{
		free(temp[index]);
		index++;
	}
	free(temp);
}

void	pipex_init(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: Insufficient parameters\n", 2);
		exit (ERROR);
	}
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		pipex->limiter = ft_strjoin(argv[2], "\n");
		pipex->file_permissions = O_CREAT | O_WRONLY | O_APPEND;
	}
	else
	{
		pipex->file_permissions = O_CREAT | O_WRONLY | O_TRUNC;
		pipex->limiter = NULL;
	}
}

void	error_free(t_pipex	*pipex)
{
	if (pipex->path_join)
		free_path(pipex->path_join);
	if (pipex->pid)
		free(pipex->pid);
	ft_close(pipex->fd[0], pipex->fd[1], pipex->infile, pipex->outfile);
	if (pipex->oldfd > -1)
		close(pipex->oldfd);
	if (pipex->headlst.list)
		ft_lstclear(&pipex->headlst.list, free_path);
	error_exit();
}

void	error_exit(void)
{
	perror("Error");
	exit(ERROR);
}

void	ft_close(int fd1, int fd2, int infile, int outfile)
{
	if (fd1 > -1)
		close(fd1);
	if (fd2 > -1)
		close(fd2);
	if (infile > -1)
		close(infile);
	if (outfile > -1)
		close(outfile);
}
