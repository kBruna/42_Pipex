/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2026/01/02 21:30:36 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	t_pipex	pipex;

	path = NULL;
	pipex = (t_pipex){0};
	arg_check(argc, argv);
	pipex_init(argc, argv, &pipex);
	pipex.path_join = arg_parse(envp);
	pipex.headlst = create_cmd_lst(argc, argv, pipex);
	ft_pipex(&pipex, envp);
	ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
	ft_wait(pipex);
	if (path)
		free(path);
	if (pipex.limiter)
		free(pipex.limiter);
	free_path(pipex.path_join);
	ft_lstclear(&pipex.headlst.list, free_path);
	pipex.headlst.list = NULL;
	return (SUCCESS);
}
