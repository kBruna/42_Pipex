/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2025/12/27 11:58:52 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_Libft/includes/libft.h"

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

void	error_exit(void)
{
	perror("Error");
	exit(ERROR);
}

void	error_free(char	*str)
{
	free_path(str);
	error_exit();
}

void	error_fd(int fd)
{
	close(fd);
	error_exit();
}

void	pipex_init(int argc, char **argv, int *infile, int *outfile)
{
	if (argc < 3)
	{
		ft_putstr_fd("Error: Insufficient parameters", 2);
		return (ERROR);
	}
	*infile = open(argv[1], O_RDONLY);
	if (*infile == -1)
		error_exit();
	if (!ft_strncmp(argv[1], "here_doc", 9))
		file_permissions = O_CREAT | O_WRONLY | O_APPEND;
	else
		file_permissions = O_CREAT | O_WRONLY | O_TRUNC;
	*onfile = open(argv[argc - 1], file_permissions, 0644);
	if (*onfile == -1)
		error_fd(*infile);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		infile;
	int		outfile;
	char	**path_split;
	char	**path_join;
	int		fd[2];
	pid_t	pid;
	int		index;
	int		idx;
	int		file_permissions;

	if (argc < 3)
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
		error_fd(infile);
	idx = 1;
	while (idx < argc - 1)
	{
		if (argv[idx][0] == '\0')
		{
			ft_putstr_fd("Error: Empty Argument given\n", STD_ERR);
			return (ERROR);
		}
		idx++;
	}
	path_split = path_parsing(envp);
	idx = 0;
	path_join = NULL;
	while (path_split[idx] != NULL)
	{
		path_join[idx] = ft_strjoin(path_split[idx], "/");
		idx++;
	}
	free_path(path_split);
	if (pipe(fd) == -1)
		error_message(path_join);
	pid = fork();
	if (pid == -1)
		error_message(path_join);
	if (pid = 0)
	{
		close(fd[0]);
		path = ft_strjoin(path_join[idx], argv[index]);
		while (access(path, X_OR) == -1)
		{
			free(path);
			path = ft_strjoin(path_join[idx], argv[index]);
		}
		if (execve(path, argv[index], envp) == -1)
		{
			free(path);
			perror("Error");
			return (ERROR);
		}
	}
	free(path);
	free_path(path_join);
	return (SUCCESS);
}
