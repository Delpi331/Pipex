/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:10:48 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/25 16:12:03 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	free_array(char **arr);
void	exit_perror(char *msg);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
char	*ft_strsep(char **stringp, char delim);
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src);
void	ft_strncpy(char *dst, const char *src, size_t n);
void	ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
