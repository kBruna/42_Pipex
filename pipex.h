/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:26:39 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 20:56:08 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./src/42_Libft/includes/libft.h"
# include "./src/42_Libft/includes/get_next_line.h"
# include "./src/42_Libft/includes/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**path_join;
	char	**cmd;
	pid_t	pid[2];
	int		fd[2];
	int		infile;
	int		outfile;
}			t_pipex;

// ----------- Parsing.c -------------
char	**path_parsing(char **envp);
char	**arg_parse(char **envp);
void	arg_check(int argc, char **argv);
void	pipex_init(int argc, char **argv, int *infile, int *outfile);
char	*find_path(char **path_join, char **cmd);

// ----------- Pipex_utils.c ---------
void	free_path(char **split);
void	error_free(char	**str, int fd1, int fd2);
void	ft_close(int fd1, int fd2, int infile, int outfile);
int		ft_wait(pid_t pid[2]);

// ----------- Pipex.c ---------------
void	pipe_dup(int fd, int infile, int outfile, char **path_join);
void	first_child(t_pipex pipex, char **envp, char **argv);
void	second_child(t_pipex pipex, char **envp, char **argv);

#endif
