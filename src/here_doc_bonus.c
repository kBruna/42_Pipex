/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:29:48 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 14:29:50 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(t_pipex *pipex)
{
	char	*buffer;
	int		limiter_size;

	buffer = NULL;
	if (pipex->limiter != NULL)
	{
		limiter_size = ft_strlen(pipex->limiter) + 1;
		if (pipe(pipex->fd) == -1)
			error_free(pipex);
		while (buffer == NULL)
		{
			write(STD_OUT, "> ", 2);
			buffer = get_next_line(STD_IN);
			if (ft_strncmp(buffer, pipex->limiter, limiter_size) == 0)
			{
				free(buffer);
				break ;
			}
			ft_putstr_fd(buffer, pipex->fd[1]);
			free(buffer);
			buffer = NULL;
		}
		pipex->oldfd = pipex->fd[0];
		close(pipex->fd[1]);
	}
}
