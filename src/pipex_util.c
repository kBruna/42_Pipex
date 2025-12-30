/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:42:24 by buehara           #+#    #+#             */
/*   Updated: 2025/12/29 17:44:10 by buehara          ###   ########.fr       */
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
