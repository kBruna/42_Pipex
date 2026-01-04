/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:26:39 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 18:36:21 by buehara          ###   ########.fr       */
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

// ----------- Parsing.c -------------
char	**path_parsing(char **envp);
char	**arg_parse(char **envp);
void	arg_check(int argc, char **argv);
void	pipex_init(int argc, char **argv, int *infile, int *outfile);

// ----------- Pipex_utils.c ---------
void	free_path(char **split);
void	error_free(char	**str, int fd1, int fd2);

// ----------- Pipex.c ---------------
void	pipe_dup(int fd, int infile, int outfile, char **path_join);


// ----------- Main.c ----------------

#endif
