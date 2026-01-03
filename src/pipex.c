/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:24:46 by buehara           #+#    #+#             */
/*   Updated: 2026/01/03 15:11:21 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_pipex(t_pipex *pipex, char **envp)
{
	int		count;
	t_list	cmdlst;

	count = 0;
	cmdlst = *pipex->headlst.list;
	init_fd(pipex);
	if (pipex->limiter != NULL)
		here_doc(pipex);
	while (count < pipex->headlst.lst_size)
	{
		if (count < pipex->headlst.lst_size - 1)
			if (pipe(pipex->fd) == -1)
				error_free(pipex);
		pipex->pid = fork();
		if (pipex->pid == -1)
			error_free(pipex);
		if (pipex->pid == 0)
			child_process(pipex, count, envp, cmdlst);
		close_and_free(pipex, &cmdlst, count);
		count++;
	}
}

void	close_and_free(t_pipex *pipex, t_list	*cmdlst, int count)
{
	close(pipex->fd[1]);
	if (count > 0 || pipex->limiter != NULL)
		close(pipex->oldfd);
	pipex->oldfd = pipex->fd[0];
	if (cmdlst->next)
		*cmdlst = *cmdlst->next;
	if (pipex->limiter != NULL)
	{
		free(pipex->limiter);
		pipex->limiter = NULL;
	}
}

void	ft_wait(t_pipex pipex)
{
	int	idx;

	idx = 0;
	while (idx < pipex.headlst.lst_size)
	{
		wait(0);
		idx++;
	}
}
