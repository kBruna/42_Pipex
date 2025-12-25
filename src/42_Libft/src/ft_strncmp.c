/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:39:30 by buehara           #+#    #+#             */
/*   Updated: 2025/10/06 20:17:44 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ctrl;

	ctrl = 0;
	if (n > 0)
	{
		while ((s1[ctrl] != '\0' || s2[ctrl] != '\0') && n--)
		{
			if (s1[ctrl] != s2[ctrl])
				return ((unsigned char)s1[ctrl] - (unsigned char)s2[ctrl]);
			ctrl++;
		}
	}
	return (0);
}
