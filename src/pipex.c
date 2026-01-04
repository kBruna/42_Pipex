/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:14:06 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 18:18:45 by buehara          ###   ########.fr       */
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
