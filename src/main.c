/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2025/12/26 16:52:19 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_Libft/includes/libft.h"
#include "42_Libft/includes/ft_printf.h"

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

int	main(int argc, char **argv, char **envp)
{
	char	*temp;
	char	**path_split;
	int		index;

	if (argc < 3)
		return (1);
	temp = argv[1];
	path_split = path_parsing(envp);
	index = 0;
	while (path_split[index] != NULL)
		ft_printf("%s\n", path_split[index++]);
	while (index >= 0)
		free(path_split[index--]);
	free(path_split);
	return (0);
}
