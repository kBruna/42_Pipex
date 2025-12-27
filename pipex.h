/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:34:40 by buehara           #+#    #+#             */
/*   Updated: 2025/12/27 18:44:39 by buehara          ###   ########.fr       */
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

char	**path_parsing(char **envp);
void	free_path(char **split);
void	error_free(char	**str, int fd1, int fd2);
void	pipex_init(int argc, char **argv, int *infile, int *outfile);
void	arg_check(int argc, char **argv, int infile, int outfile);
char	**arg_parse(char **envp);

#endif
