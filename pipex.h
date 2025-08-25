/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:43:12 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/22 16:43:12 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define ERR_ARGS "Error: Número incorrecto de argumentos.\n"
# define ERR_FILE "Error: No se puede abrir el archivo.\n"
# define ERR_CMD "Error: Comando no encontrado.\n"

void	exec_cmd(char *cmd, char **envp);
void	pipex(int fd_in, int fd_out, char **argv, char **envp);
char	**split_cmd(char *cmd);
char	*get_cmd_path(char *cmd, char **envp);
#endif