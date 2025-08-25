/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:43:04 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/29 13:20:27 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fd_in, int fd_out, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid[2];

	if (pipe(pipefd) == -1)
		exit_perror("Error al crear el pipe");
	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		exec_cmd(argv[2], envp);
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(pipefd[1]);
		exec_cmd(argv[3], envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;

	if (argc != 5)
	{
		ft_putstr_fd(ERR_ARGS, 2);
		exit(EXIT_FAILURE);
	}
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("Error");
		close(fd_in);
		exit(EXIT_FAILURE);
	}
	pipex(fd_in, fd_out, argv, envp);
	close(fd_in);
	close(fd_out);
	return (0);
}
