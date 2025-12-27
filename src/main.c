/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2025/12/27 18:45:18 by buehara          ###   ########.fr       */
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
	while (envp[index] != NULL)
	{
		if (!ft_strncmp(envp[index], "PATH", 4))
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

	if (argc < 3)
	{
		ft_putstr_fd("Error: Insufficient parameters", 2);
		exit (ERROR);
	}
	*infile = open(argv[1], O_RDONLY);
	if (*infile == -1)
		error_free(NULL, NO_FD, NO_FD);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		file_permissions = O_CREAT | O_WRONLY | O_APPEND;
	else
		file_permissions = O_CREAT | O_WRONLY | O_TRUNC;
	*outfile = open(argv[argc - 1], file_permissions, 0644);
	if (*outfile == -1)
		error_free(NULL, *infile, NO_FD);
}

void	arg_check(int argc, char **argv, int infile, int outfile)
{
	int	idx;

	idx = 1;
	while (idx < argc - 1)
	{
		if (argv[idx][0] == '\0')
		{
			ft_putstr_fd("Error: Empty Argument given\n", STD_ERR);
			close(infile);
			close(outfile);
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
	
	path_split = path_parsing(envp); // TEST OK
	idx = 0;
	path_join = NULL;
	while (path_split[idx] != NULL)
	{
		path_join[idx] = ft_strjoin(path_split[idx], "/");
		idx++;
	}
	free_path(path_split);
	return (path_join);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		infile;
	int		outfile;
	//char	**path_split;
	char	**path_join;
	//int		fd[2];
	//pid_t	pid;
	//int		index;
	int		idx;
	//int		file_permissions;

	path = NULL;
	pipex_init(argc, argv, &infile, &outfile); // TEST PENDING
/*	if (argc < 3)
	{
		ft_putstr_fd("Error: Insufficient parameters", 2);
		return (ERROR);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_exit();
	if (!ft_strncmp(argv[1], "here_doc", 9))
		file_permissions = O_CREAT | O_WRONLY | O_APPEND;
	else
		file_permissions = O_CREAT | O_WRONLY | O_TRUNC;
	onfile = open(argv[argc - 1], file_permissions, 0644);
	if (onfile == -1)
		error_fd(infile);*/

	arg_check(argc, argv, infile, outfile); // TEST PENDING
	/*idx = 1;
	while (idx < argc - 1)
	{
		if (argv[idx][0] == '\0')
		{
			ft_putstr_fd("Error: Empty Argument given\n", STD_ERR);
			close(infile);
			close(outfile);
			exit (ERROR);
		}
		idx++;
	}*/

	path_join = arg_parse(envp);
	/*path_split = path_parsing(envp); // TEST OK
	idx = 0;
	path_join = NULL;
	while (path_split[idx] != NULL)
	{
		path_join[idx] = ft_strjoin(path_split[idx], "/");
		idx++;
	}
	free_path(path_split);*/
	idx = 0;
	while (path_join[idx] != NULL)
		ft_printf("->\t%s", path_join[idx++]);
	/*path = NULL;
	if (pipe(fd) == -1)
		error_free(path_join, NO_FD, NO_FD);
	pid = fork();
	if (pid == -1)
		error_free(path_join);
	idx = 0;
	index = 0;
	if (pid == 0)
	{
		close(fd[fd_close]);
		path = ft_strjoin(path_join[idx], argv[index]);
		while (access(path, X_OK) == -1)
		{
			free(path);
			path = ft_strjoin(path_join[idx], argv[index]);
		}
		if (execve(path, &argv[index], envp) == -1)
		{
			free(path);
			perror("Error");
			return (ERROR);
		}
	}*/
	if (path)
		free(path);
	free_path(path_join);
	return (SUCCESS);
}
