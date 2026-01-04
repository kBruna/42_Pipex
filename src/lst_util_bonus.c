/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:30:05 by buehara           #+#    #+#             */
/*   Updated: 2026/01/04 14:30:08 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_head	create_cmd_lst(int argc, char **argv, t_pipex pipex)
{
	t_head	head_cmd;
	int		count;

	if (pipex.limiter != NULL)
		count = 3;
	else
		count = 2;
	head_cmd.list = ft_lstnew(ft_split(argv[count], ' '));
	head_cmd.lst_size = 1;
	count++;
	while (count < argc - 1)
	{
		ft_lstadd_back(&head_cmd.list, ft_lstnew(ft_split(argv[count], ' ')));
		count++;
		head_cmd.lst_size++;
	}
	return (head_cmd);
}
