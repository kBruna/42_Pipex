/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:13:40 by buehara           #+#    #+#             */
/*   Updated: 2025/12/16 20:43:50 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*org;
	size_t			ctrl;

	dest = (unsigned char *)dst;
	org = (unsigned char *)src;
	if ((dest == NULL) && (org == NULL))
		return (dest);
	if (*dest < *org)
	{
		ctrl = 0;
		while (ctrl < n)
		{
			dest[ctrl] = org[ctrl];
			ctrl++;
		}
		return (dest);
	}
	n--;
	while ((int)n >= 0)
	{
		dest[n] = org[n];
		n--;
	}
	return (dest);
}
