/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:53:38 by buehara           #+#    #+#             */
/*   Updated: 2025/12/30 19:54:39 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_head	create_cmd_lst(int argc, char **argv)
{
	t_head	head_cmd;
	int		count;

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

