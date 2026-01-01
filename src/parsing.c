/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:39:26 by buehara           #+#    #+#             */
/*   Updated: 2025/12/30 19:56:47 by buehara          ###   ########.fr       */
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

char	*create_path(char **path_join, char **cmd)
{
	int		idx;
	char	*path;

	idx = 0;
	if (access(cmd[0], F_OK | X_OK) == -1)
	{
		path = ft_strjoin(path_join[idx], cmd[0]);
		if (!path)
			error_exit();
		while (access(path, F_OK | X_OK) == -1)
		{
			idx++;
			free(path);
			path = ft_strjoin(path_join[idx], cmd[0]);
			if (!path)
				error_exit();
		}
		if (!path)
			error_exit();
	}
	else
		path = cmd[0];
	return (path);
}

