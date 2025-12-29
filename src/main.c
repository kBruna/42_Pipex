/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2025/12/28 20:55:32 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**path_parsing(char **envp)
{
	int		index;
	char	*temp;
	char	*env_path;
	char	**path_split;

	index = 0;
	env_path = NULL;
	while (envp[index] != NULL)
	{
		if (!ft_strncmp(envp[index], "PATH=", 5))
		{
			env_path = envp[index];
			break ;
		}
		index++;
	}
	path_split = ft_split(env_path, ':');
	temp = path_split[0];
	path_split[0] = ft_strdup(ft_strchr(temp, '/'));
	free(temp);
	return (path_split);
}

void	free_path(char **split)
{
	int	index;

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
		error_free(NULL, NO_FD, NO_FD);
}

void	arg_check(int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (argv[idx][0] == '\0')
		{
			ft_putstr_fd("Error: Empty Argument given\n", STD_ERR);
			exit (ERROR);
		}
		idx++;
	}
}

char	**arg_parse(char **envp)
{
	int		idx;
	char	**path_split;
	char	**path_join;
	
	path_split = path_parsing(envp);
	idx = 0;
	path_join = NULL;
	while (path_split[idx] != NULL)
		idx++;
	path_join = ft_calloc(++idx, sizeof(char *));
	idx = 0;
	while (path_split[idx] != NULL)
	{
		path_join[idx] = ft_strjoin(path_split[idx], "/");
		idx++;
	}
	path_join[idx] = NULL;
	free_path(path_split);
	return (path_join);
}

typedef struct	s_cmd
{
	char	**cmd1;
	char	**cmd2;
}				t_cmd;

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

	cmd.cmd1 = ft_split(argv[2], ' ');
	cmd.cmd2 = ft_split(argv[3], ' ');
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
		if (access(cmd.cmd1[0], X_OK) == -1)
		{
			path = ft_strjoin(path_join[idx], cmd.cmd1[0]);
			if (!path)		// MALLOC ERROR 
				exit (ERROR);
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
		free_path(cmd.cmd2);
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
		if (access(cmd.cmd2[0], X_OK) == -1)
		{
			path = ft_strjoin(path_join[idx], cmd.cmd2[0]);
			if (!path)		// MALLOC ERROR 
				exit (ERROR);
			while (path && access(path, X_OK) == -1)
			{
				idx++;
				free(path);
				path = ft_strjoin(path_join[idx], cmd.cmd2[0]);
				if (!path)		// MALLOC ERROR
					exit (ERROR);
			}
			if (!path)
				exit (ERROR);
		}
		else
			path = cmd.cmd2[0];
		free_path(cmd.cmd1);
		if (execve(path, cmd.cmd2, envp) == -1)
		{
			free(path);
			error_free(path_join, infile, outfile);
		}
	}
	wait(0);
	wait(0);
	if (path)
		free(path);
	free_path(path_join);
	free_path(cmd.cmd1);
	free_path(cmd.cmd2);
	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	return (SUCCESS);
}
