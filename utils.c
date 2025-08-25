/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:43:09 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/22 16:43:09 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = split_cmd(cmd);
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		ft_putstr_fd(ERR_CMD, 2);
		free_array(args);
		exit(EXIT_FAILURE);
	}
	execve(path, args, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

char	**split_cmd(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		exit_perror("Error al dividir el comando");
	return (args);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	*dir;
	char	*full_path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path = envp[i] + 5;
	dir = ft_strsep(&path, ':');
	while (dir != NULL)
	{
		full_path = ft_strjoin3(dir, "/", cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		dir = ft_strsep(&path, ':');
	}
	return (NULL);
}
