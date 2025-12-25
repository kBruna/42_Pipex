/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:42:37 by buehara           #+#    #+#             */
/*   Updated: 2025/10/06 20:17:44 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					ctrl;
	unsigned char			*copy;
	unsigned const char		*original;

	if (n == 0 || (!src && !dest))
		return (dest);
	ctrl = 0;
	copy = dest;
	original = src;
	while (ctrl < n)
	{
		copy[ctrl] = original[ctrl];
		ctrl++;
	}
	return (dest);
}
