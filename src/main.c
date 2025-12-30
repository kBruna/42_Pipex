/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2025/12/29 18:16:22 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex_init(int argc, char **argv, int *infile, int *outfile)
{
	int	file_permissions;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Insufficient parameters\n", 2);
		exit (ERROR);
	}
	if (!ft_strncmp(argv[1], "here_doc", 9))
		file_permissions = O_CREAT | O_WRONLY | O_APPEND;
	else
		file_permissions = O_CREAT | O_WRONLY | O_TRUNC;
	*outfile = open(argv[argc - 1], file_permissions, 0644);
	if (*outfile == -1)
		error_free(NULL, NO_FD, NO_FD);
	*infile = open(argv[1], O_RDONLY);
	if (*infile == -1)
		error_free(NULL, *outfile, NO_FD);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		infile;
	int		outfile;
	char	**path_join;
	t_cmd	cmd;
	int		fd[2];
	pid_t	pid[2];
	int		index;
	int		idx;

	path = NULL;
	arg_check(argc, argv); // TEST OK insofar
	pipex_init(argc, argv, &infile, &outfile); // TEST OK insofar
	path_join = arg_parse(envp); // TEST OK insofar

//	idx = 0;							// Test PRINT LOOP
//	while (path_join[idx] != NULL)
//		ft_printf("->\t%s\n", path_join[idx++]);

	path = NULL;
	if (pipe(fd) == -1)
		error_free(path_join, infile, outfile);
	pid[0] = fork();
	if (pid[0] == -1)
		error_free(path_join, infile, outfile);
	idx = 0;
	index = 0;
	if (pid[0] == 0)
	{
		if (dup2(infile, 0) == -1)
		{
			close(fd[1]);
			error_free(path_join, infile, outfile);
		}
		if (dup2(fd[1], 1) == -1)
		{
			close(fd[1]);
			error_free(path_join, infile, outfile);
		}
		close(fd[0]);
		close(outfile);
		close(infile);
		close(fd[1]);
		cmd.cmd1 = ft_split(argv[2], ' ');
		if (!cmd.cmd1)
			exit (ERROR);
		if (access(cmd.cmd1[0], F_OK | X_OK) == -1)
		{
			path = ft_strjoin(path_join[idx], cmd.cmd1[0]);
			if (!path)
				error_free(cmd.cmd1, NO_FD, NO_FD);
			while (path && access(path, X_OK) == -1)
			{
				idx++;
				free(path);
				path = ft_strjoin(path_join[idx], cmd.cmd1[0]);
				if (!path)
					exit (ERROR);
			}
			if (!path)
				exit (ERROR);
		}
		else
			path = cmd.cmd1[0];
		if (execve(path, cmd.cmd1, envp) == -1)
		{
			free(path);
			error_free(path_join, infile, outfile);
		}
	}
	close(fd[1]);
	pid[1] = fork();
	if (pid[1] == -1)
		error_free(path_join, infile, outfile);
	if (pid[1] == 0)
	{
		if (dup2(fd[0], 0) == -1)
		{
			close(fd[0]);
			error_free(path_join, infile, outfile);
		}
		if (dup2(outfile, STD_OUT) == -1)
			error_free(path_join, infile, outfile);
		close(infile);
		close(fd[0]);
		close(outfile);
		cmd.cmd2 = ft_split(argv[3], ' ');
		if (!cmd.cmd2)
			exit (ERROR);
		if (access(cmd.cmd2[0], X_OK) == -1)
		{
			path = ft_strjoin(path_join[idx], cmd.cmd2[0]);
			if (!path)
				free_error(cmd.cmd2, NO_FD, NO_FD);
			while (path && access(path, X_OK) == -1)
			{
				idx++;
				free(path);
				path = ft_strjoin(path_join[idx], cmd.cmd2[0]);
				if (!path)
					free_path(cmd.cmd2, NO_FD, NO_FD);
			}
			if (!path)
				free_path(cmd.cmd2, NO_FD, NO_FD);
		}
		else
			path = cmd.cmd2[0];
		if (execve(path, cmd.cmd2, envp) == -1)
		{
			free(path);
			error_free(path_join, infile, outfile);
		}
	}
	if (path)
		free(path);
	free_path(path_join);
	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	wait(0);
	wait(0);
	return (SUCCESS);
}
