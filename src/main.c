/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:15:09 by buehara           #+#    #+#             */
/*   Updated: 2025/12/30 22:08:32 by buehara          ###   ########.fr       */
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
//	t_list *temp;
//	
//	temp = headlst.list;
//	idx = 0;							// Test PRINT LOOP
//	while (temp != NULL)
//	{
//		ft_printf(" ->\t%s\n", ((char **)temp->content)[0]);
//		temp = temp->next;
//	}

	int	count;

	count = 0;
	pipex.oldfd = -1;
	pipex.fd[0] = -1;
	pipex.fd[1] = -1;
	pipex.file[0] = -1;
	pipex.file[1] = -1;
	cmdlst = *pipex.headlst.list;
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
			if (pipex.oldfd == -1)
			{
				//pipex.file[0] = open(pipex.infile, O_RDONLY);
				//if (pipex.file[0] == -1)
					//error_free(&pipex);
				if (dup2(pipex.infile, STD_IN) == -1)
					error_free(&pipex);
			}
			else
				if (dup2(pipex.oldfd, STD_IN) == -1)
					error_free(&pipex);
			if (count == pipex.headlst.lst_size - 1)
			{
				//pipex.file[1] = open(pipex.outfile, pipex.file_permissions, 0644);
				//if (pipex.file[1] == -1)
					//error_free(&pipex);
				if (dup2(pipex.outfile, STD_OUT == -1))
					error_free(&pipex);
			}
			else
				if (dup2(pipex.fd[1], STD_OUT) == -1)
					error_free(&pipex);
			ft_close(pipex.oldfd, pipex.fd[1], pipex.file[0], pipex.file[0]);
			path = create_path(pipex.path_join, cmdlst.content);
			execve(path, cmdlst.content, envp);
			free(path);
			error_free(&pipex);
		}
		close(pipex.fd[1]);
		if (pipex.oldfd != -1)
			close(pipex.oldfd);
		if (count < pipex.headlst.lst_size - 1)
			pipex.oldfd = pipex.fd[0];
		if (cmdlst.next)
			cmdlst = *cmdlst.next;
		count++;
	}
	/*cmdlst = *cmdlst.next;
	pid[1] = fork();
	if (pid[1] == -1)
		error_free(path_join, pipex.file[0], pipex.file[1]);
	if (pid[1] == 0)
	{
		if (dup2(fd[0], STD_IN) == -1)
		{
			close(fd[0]);
			error_free(path_join, pipex.file[0], pipex.file[1]);
		}
		if (dup2(outfile, STD_OUT) == -1)
		{
			close(fd[1]);
			error_free(path_join, pipex.file[0], pipex.file[1]);
		}
		ft_close(fd[0], fd[1], infile, outfile);
		path = create_path(path_join, cmdlst.content);
		execve(path, cmdlst.content, envp);
		free(path);
		error_free(path_join, pipex.file[0], pipex.file[1]);
	}*/
	ft_close(pipex.fd[0], pipex.fd[1], pipex.file[0], pipex.file[1]);
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
