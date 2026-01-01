/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:42:24 by buehara           #+#    #+#             */
/*   Updated: 2025/12/30 21:37:47 by buehara          ###   ########.fr       */
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
	pipex->outfile = open(argv[argc - 1], pipex->file_permissions, 0644);
	if (pipex->outfile == -1)
		error_free(pipex);
	if (pipex->limiter)
	{
		pipex->infile = open(argv[3], O_RDONLY); // IF HERE_DOC idx == 2;
		if (pipex->infile == -1)
			error_free(pipex);
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			error_free(pipex);
	}
	//pipex->outfile = argv[argc - 1];
	//pipex->infile = argv[1]; // IF HERE_DOC idx == 2;
}

void	error_free(t_pipex	*pipex)
{
	if (pipex->path_join)
		free_path(pipex->path_join);
	if (pipex->pid)
		free(pipex->pid);
	ft_close(pipex->fd[0], pipex->fd[1], pipex->file[0], pipex->file[1]);
	if (pipex->oldfd > -1)
		close(pipex->oldfd);
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
