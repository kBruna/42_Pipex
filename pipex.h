/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:34:40 by buehara           #+#    #+#             */
/*   Updated: 2026/01/01 19:13:17 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PIPEX_H
# define	PIPEX_H

# include "./src/42_Libft/includes/libft.h"
# include "./src/42_Libft/includes/get_next_line.h"
# include "./src/42_Libft/includes/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct	s_cmd
{
	char	**cmd1;
	char	**cmd2;
}				t_cmd;

typedef struct	s_head
{
	int	lst_size;
	t_list	*list;
}				t_head;

typedef struct s_pipex
{
	t_head	headlst;
	char	**path_join;
	char	*limiter;
	int		file_permissions;
	pid_t	*pid;
	int		fd[2];
	int		oldfd;
	int		infile;
	int		outfile;
}				t_pipex;

// ----------- Parsing.c -------------
char	**path_parsing(char **envp);
char	**arg_parse(char **envp);
char	*create_path(char **path_join, char **cmd, t_pipex *pipex);
void	arg_check(int argc, char **argv);

// ----------- Pipex_utils.c ---------
void	free_path(void *split);
void	error_exit(void);
void	error_free(t_pipex *pipex);
void	pipex_init(int argc, char **argv, t_pipex *pipex);
void	ft_close(int fd1, int fd2, int infile, int outfile);

// ----------- lst_util.c -----------
t_head	create_cmd_lst(int argc, char **argv);

// ----------- Main.c ----------------

#endif
