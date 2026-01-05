/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:28:08 by buehara           #+#    #+#             */
/*   Updated: 2026/01/05 18:44:52 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./src/42_Libft/includes/libft.h"
# include "./src/42_Libft/includes/get_next_line.h"
# include "./src/42_Libft/includes/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_head
{
	int		lst_size;
	t_list	*list;
}				t_head;

typedef struct s_pipex
{
	t_head	headlst;
	char	**path_join;
	char	*limiter;
	char	*arg_out;
	char	*arg_in;
	pid_t	*pid;
	int		fd[2];
	int		permission;
	int		oldfd;
	int		infile;
	int		outfile;
}				t_pipex;

// ----------- Parsing.c -------------
char	**path_parsing(char **envp);
char	**arg_parse(char **envp);
char	*create_path(char **path_join, char **cmd, t_pipex *pipex);
void	arg_check(int argc, char **argv);
void	init_fd(t_pipex *pipex);

// ----------- Pipex_utils.c ---------
void	free_path(void *split);
void	error_exit(void);
void	error_free(t_pipex *pipex);
void	pipex_init(int argc, char **argv, t_pipex *pipex);
void	ft_close(int fd1, int fd2, int infile, int outfile);

// ----------- lst_util.c -----------
t_head	create_cmd_lst(int argc, char **argv, t_pipex pipex);

// ----------- here_doc_bonus.c ------
void	here_doc(t_pipex *pipex);

// ----------- child.c ---------------
void	define_std_input(t_pipex *pipex, int count);
void	define_std_output(t_pipex *pipex, int count);
void	execve_run(t_pipex *pipex, t_list cmdlst, char **envp);
void	child_process(t_pipex *pipex, int count, char **envp, t_list cmdlst);

// ----------- Pipex.c ---------------
int		ft_wait(t_pipex pipex);
void	close_and_free(t_pipex *pipex, t_list	*cmdlst, int count);
void	ft_pipex(t_pipex *pipex, char **envp);

#endif
