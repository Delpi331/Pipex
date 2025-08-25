/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:20:07 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/25 16:20:32 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**gestion(int word_count)
{
	char	**result;

	result = malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[word_count] = NULL;
	return (result);
}

static int	n_wrl(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*next(char const *s, char c, int *i)
{
	int	start;
	int	end;

	start = *i;
	while (s[start] == c && s[start] != '\0')
		start++;
	end = start;
	while (s[end] != c && s[end] != '\0')
		end++;
	*i = end;
	return (ft_substr(s, start, end - start));
}

static char	**splitear(char const *s, char c, int word_count)
{
	char	**result;
	int		i;
	int		j;

	result = gestion(word_count);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		result[j] = next(s, c, &i);
		if (result[j] == NULL)
		{
			while (j > 0)
				free(result[--j]);
			free(result);
			return (NULL);
		}
		j++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int	word_count;

	if (s == NULL)
		return (NULL);
	word_count = n_wrl(s, c);
	return (splitear(s, c, word_count));
}
