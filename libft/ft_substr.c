/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:01:07 by ddel-pin          #+#    #+#             */
/*   Updated: 2024/10/08 17:22:00 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gest(size_t len)
{
	char	*p;

	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[0] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (len == 0 || start >= s_len)
		return (gest(0));
	if (len > s_len - start)
		len = s_len - start;
	p = gest(len);
	if (p == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
