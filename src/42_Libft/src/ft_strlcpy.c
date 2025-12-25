/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:51:13 by buehara           #+#    #+#             */
/*   Updated: 2025/11/24 16:13:00 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	int		ctrl;

	count = 0;
	ctrl = 0;
	while (src[ctrl] != '\0')
		ctrl++;
	if (size > 0)
	{
		while ((src[count] != '\0') && (count < size - sizeof(char)))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (ctrl);
}
