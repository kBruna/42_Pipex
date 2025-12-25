/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:50:33 by buehara           #+#    #+#             */
/*   Updated: 2025/10/06 20:17:44 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ctrl_l;
	size_t	ctrl_b;

	ctrl_b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[ctrl_b] && ctrl_b < len)
	{
		ctrl_l = 0;
		while (little[ctrl_l] != '\0' && ctrl_l + ctrl_b < len)
		{
			if (little[ctrl_l] != big[ctrl_b + ctrl_l])
				break ;
			ctrl_l++;
			if (little[ctrl_l] == '\0')
				return ((char *)&big[ctrl_b]);
		}
		ctrl_b++;
	}
	return (NULL);
}
