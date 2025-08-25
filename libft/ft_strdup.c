/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:20:49 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/29 13:08:00 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	ft_strcpy(copy, s);
	return (copy);
}
