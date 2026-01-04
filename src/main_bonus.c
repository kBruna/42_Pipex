/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:30:19 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 14:30:21 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exit(int status)
{
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		exit(128 + WTERMSIG(status));
	exit (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	t_pipex	pipex;
	int		status;

	path = NULL;
	pipex = (t_pipex){0};
	arg_check(argc, argv);
	pipex_init(argc, argv, &pipex);
	pipex.path_join = arg_parse(envp);
	pipex.headlst = create_cmd_lst(argc, argv, pipex);
	ft_pipex(&pipex, envp);
	ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
	status = ft_wait(pipex);
	if (path)
		free(path);
	if (pipex.limiter)
		free(pipex.limiter);
	free_path(pipex.path_join);
	ft_lstclear(&pipex.headlst.list, free_path);
	pipex.headlst.list = NULL;
	ft_exit(status);
	return (0);
}
