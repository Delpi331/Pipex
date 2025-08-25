/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:22:16 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/25 16:15:03 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, char delim)
{
	char	*start;
	char	*end;

	start = *stringp;
	if (!start)
		return (NULL);
	end = ft_strchr(start, delim);
	if (end)
	{
		*end = '\0';
		*stringp = end + 1;
	}
	else
		*stringp = NULL;
	return (start);
}
