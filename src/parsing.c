/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:30:32 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 21:19:47 by buehara          ###   ########.fr       */
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

char	*find_path(char **path_join, char **cmd)
{
	char	*path;
	int		idx;

	path = NULL;
	idx = 0;
	if (access(cmd[0], F_OK | X_OK) == -0)
		return (cmd[0]);
	path = ft_strjoin(path_join[idx], cmd[0]);
	if (!path)
		error_free(cmd, NO_FD, NO_FD);
	while (path && access(path, X_OK) == -1)
	{
		idx++;
		free(path);
		path = ft_strjoin(path_join[idx], cmd[0]);
		if (!path)
		{
			free_path(path_join);
			free_path(cmd);
			exit(127);
		}
	}
	return (path);
}
