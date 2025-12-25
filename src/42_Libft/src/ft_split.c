/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:25:04 by buehara           #+#    #+#             */
/*   Updated: 2025/10/06 20:17:44 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	ctrl;

	ctrl = 0;
	count = 0;
	if (s[ctrl] == c)
		while (s[ctrl] && s[ctrl] == c)
			ctrl++;
	while (s[ctrl] != '\0')
	{
		while (s[ctrl] && s[ctrl] != c)
			ctrl++;
		if (s[ctrl] == c || s[ctrl] == '\0')
		{
			count++;
			while (s[ctrl] && s[ctrl] == c)
				ctrl++;
		}
	}
	return (count);
}

static void	ft_word_runner(char const *s, char c, size_t *start, size_t *end)
{
	if (s[*end] && s[*end] == c && *end < ft_strlen(s))
	{
		while (s[*end] && s[*end] == c && *end < ft_strlen(s))
		{
			(*end)++;
		}
		*start = *end;
	}
	else if (s[*end] && s[*end] != c)
	{
		while (s[*end] && s[*end] != c)
		{
			(*end)++;
		}
	}
}

static void	*ft_free(char **ptr, size_t ctrl)
{
	size_t	index;

	index = 0;
	if (!ptr[ctrl - 1])
	{
		while (index <= ctrl)
		{
			free(ptr[index]);
			index++;
		}
		free(ptr);
	}
	return (NULL);
}

static char	**ft_alloc(char const *s, char **ptr, char c)
{
	size_t	ctrl;
	size_t	end;
	size_t	start;

	ctrl = 0;
	end = 0;
	start = 0;
	while (s[end] != '\0')
	{
		ft_word_runner(s, c, &start, &end);
		if (end > start)
		{
			ptr[ctrl] = ft_substr(s, start, end - start);
			if (ptr[ctrl] == NULL)
			{
				ft_free(ptr, ctrl);
				return (NULL);
			}
			ctrl++;
		}
	}
	ptr[ctrl] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char		**ptr;

	if (!s)
		return (NULL);
	ptr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = ft_alloc(s, ptr, c);
	if (!ptr)
		return (NULL);
	return (ptr);
}
