/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:32:36 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 20:44:48 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_path(char **split)
{
	int	index;

	if (!split)
		return ;
	index = 0;
	while (split[index] != NULL)
	{
		free(split[index]);
		index++;
	}
	free(split);
}

void	error_free(char	**str, int fd1, int fd2)
{
	if (str)
		free_path(str);
	if (fd1 != NO_FD)
		close(fd1);
	if (fd2 != NO_FD)
		close(fd2);
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

int	ft_wait(pid_t pid[2])
{
	int	idx;
	int	status;

	idx = 0;
	while (idx < 2)
	{
		waitpid(pid[idx], &status, 0);
		idx++;
	}
	return (status);
}
