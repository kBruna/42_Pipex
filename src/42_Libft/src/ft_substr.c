/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:13:22 by buehara           #+#    #+#             */
/*   Updated: 2025/10/06 20:17:44 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (ft_strlen(s) < start)
		ptr = malloc(1);
	else if (ft_strlen(&s[start]) >= len)
		ptr = malloc(len + 1);
	else
		ptr = malloc((int)(ft_strlen(&s[start]) + 1));
	if (ptr == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		*ptr = '\0';
	else if (ft_strlen(&s[start]) >= len)
		ft_strlcpy(ptr, &s[start], len + 1);
	else
		ft_strlcpy(ptr, &s[start], (ft_strlen(s) + 1));
	return (ptr);
}
