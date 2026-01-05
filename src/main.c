/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:26:22 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 20:46:47 by buehara          ###   ########.fr       */
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
	t_pipex	pipex;
	int		status;

	pipex = (t_pipex){0};
	arg_check(argc, argv);
	pipex_init(argc, argv, &pipex.infile, &pipex.outfile);
	pipex.path_join = arg_parse(envp);
	if (pipe(pipex.fd) == -1)
		error_free(pipex.path_join, pipex.infile, pipex.outfile);
	first_child(pipex, envp, argv);
	second_child(pipex, envp, argv);
	free_path(pipex.path_join);
	ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
	status = ft_wait(pipex.pid);
	ft_exit(status);
	return (SUCCESS);
}
