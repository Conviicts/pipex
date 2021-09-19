/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:46:46 by vserra            #+#    #+#             */
/*   Updated: 2021/09/19 06:05:41 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_pipe1(char *cmd, char **s1, int fd[2])
{
	dup2(fd[WRITE], 1);
	close(fd[READ]);
	close(fd[WRITE]);
	execve(cmd, s1, NULL);
	exit(EXIT_SUCCESS);
}

static void	exec_pipe2(char *cmd2, char **s2, int fd[2])
{
	dup2(fd[READ], 0);
	close(fd[READ]);
	close(fd[WRITE]);
	execve(cmd2, s2, NULL);
	exit(EXIT_SUCCESS);
}

void	exec_pipe(t_cmd *cmd, t_cmd *cmd2)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
	int		status;
	int		status2;

	if (pipe(fd) == -1)
		write_error("pipe", "Error Piping\n");
	pid = fork();
	if (pid < 0)
		write_error("pipe", "Error Forking\n");
	if (pid == 0)
		exec_pipe1(cmd->cmd, cmd->args, fd);
	pid2 = fork();
	if (pid2 < 0)
		write_error("pipe", "Error Forking\n");
	if (pid2 == 0)
		exec_pipe2(cmd2->cmd, cmd2->args, fd);
	close(fd[READ]);
	close(fd[WRITE]);
	waitpid(pid, &status, 0);
	waitpid(pid2, &status2, 0);
}
