/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:26:22 by buehara           #+#    #+#             */
/*   Updated: 2026/01/05 18:50:57 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	pipex_init(int argc, char **argv, int *infile, int *outfile)
{
	int	file_permissions;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Insufficient parameters\n", 2);
		exit (ERROR);
	}
	file_permissions = O_CREAT | O_WRONLY | O_TRUNC;
	*outfile = open(argv[argc - 1], file_permissions, 0644);
	if (*outfile == -1)
		perror("Invalid Outfile");
	*infile = open(argv[1], O_RDONLY);
	if (*infile == -1)
		perror("Invalid Infile");
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
		error_free(pipex.path_join, pipex.infile, pipex.outfile, "Pipe");
	first_child(pipex, envp, argv);
	close(pipex.fd[1]);
	second_child(pipex, envp, argv);
	free_path(pipex.path_join);
	ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
	status = ft_wait(pipex.pid);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		exit(WTERMSIG(status));
	return (SUCCESS);
}
