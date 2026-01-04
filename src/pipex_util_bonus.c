/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:31:10 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 14:31:12 by buehara          ###   ########.fr       */
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
	if (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6)
	{
		ft_putstr_fd("Error: Insufficient parameters for here_doc\n", 2);
		exit (ERROR);
	}
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		pipex->limiter = ft_strjoin(argv[2], "\n");
		pipex->permission = O_CREAT | O_WRONLY | O_APPEND;
	}
	else
	{
		pipex->permission = O_CREAT | O_WRONLY | O_TRUNC;
		pipex->limiter = NULL;
		pipex->arg_in = argv[1];
	}
	pipex->arg_out = argv[argc - 1];
}

void	error_free(t_pipex	*pipex)
{
	if (pipex->path_join)
		free_path(pipex->path_join);
	ft_close(pipex->fd[0], pipex->fd[1], pipex->infile, pipex->outfile);
	if (pipex->oldfd > -1)
		close(pipex->oldfd);
	if (pipex->headlst.list)
		ft_lstclear(&pipex->headlst.list, free_path);
	if (pipex->limiter != NULL)
		free(pipex->limiter);
	free(pipex->pid);
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
