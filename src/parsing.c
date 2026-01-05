/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:30:32 by buehara           #+#    #+#             */
/*   Updated: 2026/01/05 18:51:04 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**path_parsing(char **envp)
{
	int		index;
	char	*env_path;
	char	**path_split;

	index = 0;
	env_path = NULL;
	if (!envp)
		return (NULL);
	while (envp[index] != NULL)
	{
		if (!ft_strncmp(envp[index], "PATH=", 5))
		{
			env_path = envp[index];
			break ;
		}
		index++;
	}
	if (env_path == NULL)
		return (NULL);
	path_split = ft_split(&env_path[5], ':');
	if (!path_split)
		return (NULL);
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
	while (path_split && path_split[idx] != NULL)
		idx++;
	path_join = ft_calloc(++idx, sizeof(char *));
	idx = 0;
	while (path_split && path_split[idx] != NULL)
	{
		path_join[idx] = ft_strjoin(path_split[idx], "/");
		idx++;
	}
	path_join[idx] = NULL;
	free_path(path_split);
	return (path_join);
}

char	*check_path(char **cmd)
{
	if (access(cmd[0], F_OK | X_OK) == -0)
		return (cmd[0]);
	else
		return (NULL);
}

char	*find_path(char **path_join, char **cmd)
{
	char	*path;
	int		idx;

	idx = 0;
	if (ft_strchr(cmd[0], '/'))
		return (check_path(cmd));
	if (!path_join || !path_join[0])
	{
		ft_putstr_fd("Error: Path not set\n", STD_ERR);
		free_path(path_join);
		exit(127);
	}
	while (path_join[idx] != NULL)
	{
		path = ft_strjoin(path_join[idx], cmd[0]);
		if (!path)
			error_path(path_join, cmd, ERROR, "Malloc");
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		idx++;
		free(path);
	}
	if (!path)
		error_path(path_join, cmd, 127, "Command not found");
	return (NULL);
}
