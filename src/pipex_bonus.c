/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:32:10 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 15:32:20 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_pipex(t_pipex *pipex, char **envp)
{
	int		count;
	t_list	cmdlst;

	count = 0;
	cmdlst = *pipex->headlst.list;
	pipex->pid = ft_calloc(pipex->headlst.lst_size, sizeof(pid_t));
	init_fd(pipex);
	if (pipex->limiter != NULL)
		here_doc(pipex);
	while (count < pipex->headlst.lst_size)
	{
		if (count < pipex->headlst.lst_size - 1)
			if (pipe(pipex->fd) == -1)
				error_free(pipex);
		pipex->pid[count] = fork();
		if (pipex->pid[count] == -1)
			error_free(pipex);
		if (pipex->pid[count] == 0)
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

int	ft_wait(t_pipex pipex)
{
	int	idx;
	int	status;

	idx = 0;
	while (idx < pipex.headlst.lst_size)
	{
		waitpid(pipex.pid[idx], &status, 0);
		idx++;
	}
	free(pipex.pid);
	return (status);
}
