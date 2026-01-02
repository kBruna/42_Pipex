/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2026/01/01 21:17:07 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	//int		infile;
	//int		outfile;
	//char	**path_join;
	//int		fd[2];
	//pid_t	pid[2];
	//int		index;
	//int		idx;
	//t_head	headlst;
	t_list	cmdlst;
	int		wait_idx;
	t_pipex	pipex;

	path = NULL;
	pipex = (t_pipex){0};
	arg_check(argc, argv); // TEST OK insofar
	pipex_init(argc, argv, &pipex); // TEST OK insofar
	pipex.path_join = arg_parse(envp); // TEST OK insofar
	pipex.headlst = create_cmd_lst(argc, argv); // TEST OK insofar

	// TEST PRINT LOOP
	/*t_list *temp;
	
	temp = pipex.headlst.list;
	idx = 0;							// Test PRINT LOOP
	while (temp != NULL)
	{
		ft_printf(" ->\t%s\n", ((char **)temp->content)[0]);
		temp = temp->next;
	}*/

	int	count;
	char	*buffer;

	count = 0;
	pipex.oldfd = -1;
	pipex.fd[0] = -1;
	pipex.fd[1] = -1;
	pipex.infile = -1;
	pipex.outfile = -1;
	cmdlst = *pipex.headlst.list;
	buffer = NULL;
	pipex.pid = (pid_t *)ft_calloc(pipex.headlst.lst_size, sizeof(pid_t));
	path = NULL;
	while (count < pipex.headlst.lst_size)
	{
		if (count < pipex.headlst.lst_size - 1)
			if (pipe(pipex.fd) == -1)
				error_free(&pipex);
		pipex.pid[count] = fork();
		if (pipex.pid[count] == -1)
			error_free(&pipex);
		if (pipex.pid[count] == 0)	// CHILD PROCCESS
		{
			if (count == 0)
			{
				if (pipex.limiter)
				{
					while (ft_strncmp(buffer, pipex.limiter, ft_strlen(pipex.limiter)));
					{
						buffer = get_next_line(STD_IN);
						
						write(STD_OUT, buffer, ft_strlen(buffer);
					}
				}
				pipex.infile = open(argv[1], O_RDONLY);
				if (pipex.infile == -1)
					error_free(&pipex);
				if (dup2(pipex.infile, STD_IN) == -1)
					error_free(&pipex);
				close(pipex.infile);
			}
			else
			{
				if (dup2(pipex.oldfd, STD_IN) == -1)
					error_free(&pipex);
			}
			if (count < pipex.headlst.lst_size - 1)
			{
				if (dup2(pipex.fd[1], STD_OUT) == -1)
					error_free(&pipex);
			}
			else
			{
				pipex.outfile = open(argv[argc - 1], pipex.file_permissions, 0644);
				if (pipex.outfile == -1)
					error_free(&pipex);
				if (dup2(pipex.outfile, STD_OUT) == -1)
					error_free(&pipex);
				close(pipex.outfile);
			}
			ft_close(pipex.oldfd, pipex.fd[1], pipex.fd[0], NO_FD);
			path = create_path(pipex.path_join, cmdlst.content, &pipex);
			if (!path)
			{
				free_path(pipex.path_join);
				free(pipex.pid);
				ft_lstclear(&pipex.headlst.list, free_path);
				perror("Command Not Found");
				exit(ERROR);
			}
			execve(path, cmdlst.content, envp);
			error_free(&pipex);
		}
		close(pipex.fd[1]);
		if (count > 0)
			close(pipex.oldfd);
		pipex.oldfd = pipex.fd[0];
		if (cmdlst.next)
			cmdlst = *cmdlst.next;
		count++;
	}
	ft_close(pipex.fd[0], pipex.fd[1], pipex.infile, pipex.outfile);
	wait_idx = 0;
	while (wait_idx < pipex.headlst.lst_size)
	{
		wait(0);
		wait_idx++;
	}
	if (path)
		free(path);
	if (pipex.limiter)
		free(pipex.limiter);
	free_path(pipex.path_join);
	free(pipex.pid);
	ft_lstclear(&pipex.headlst.list, free_path);
	pipex.headlst.list = NULL;
	return (SUCCESS);
}
