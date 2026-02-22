/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:23:39 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/11 10:23:41 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	cmd1(int pipefd[2], int infile, char *argv[], char *envp[])
{
	char	**cmd_arg;
	char	*cmd_path;
	char	*cmd;

	if (infile >= 0)
	{
		if (dup2(infile, STDIN_FILENO) == -1)
			error_exit("dup2 infile", pipefd, infile, -1);
	}
	else
		close(STDIN_FILENO);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		error_exit("dup2 pipe write", pipefd, infile, -1);
	closer(pipefd, infile, -1, 0);
	cmd_arg = ft_split(argv[2], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	cmd_path = return_path_cmd(envp, cmd);
	execve(cmd_path, cmd_arg, envp);
	perror("execve");
	free(cmd);
	free_splited(cmd_arg);
	if (cmd_path != cmd)
		free(cmd_path);
	exit(126);
}

void	cmd2(int pipefd[2], int outfile, char *argv[], char *envp[])
{
	char	**cmd_arg;
	char	*cmd_path;
	char	*cmd;

	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		error_exit("dup2 pipe read", pipefd, -1, outfile);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_exit("dup2 outfile", pipefd, -1, outfile);
	closer(pipefd, -1, outfile, 1);
	cmd_arg = ft_split(argv[3], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	cmd_path = return_path_cmd(envp, cmd);
	execve(cmd_path, cmd_arg, envp);
	perror("execve");
	free(cmd);
	free_splited(cmd_arg);
	if (cmd_path != cmd)
		free(cmd_path);
	exit(126);
}

void	proc_cmd(int pipefd[2], int in_or_out[2], char *argv[], char *envp[])
{
	pid_t	pid_cmd1;
	pid_t	pid_cmd2;

	pid_cmd1 = fork();
	if (pid_cmd1 < 0)
		error_exit("fork", pipefd, in_or_out[0], -1);
	if (pid_cmd1 == 0)
		cmd1(pipefd, in_or_out[0], argv, envp);
	pid_cmd2 = fork();
	if (pid_cmd2 < 0)
		error_exit("fork", pipefd, -1, in_or_out[1]);
	if (pid_cmd2 == 0)
		cmd2(pipefd, in_or_out[1], argv, envp);
	closer(pipefd, in_or_out[0], in_or_out[1], 2);
	waitpid(pid_cmd1, NULL, 0);
	waitpid(pid_cmd2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	in_or_out[2];
	int	pipefd[2];

	if (!check_arg(argc, argv))
		return (1);
	in_or_out[0] = open_fd(argv[1], 0, -1);
	in_or_out[1] = open_fd(argv[4], 1, in_or_out[0]);
	if (pipe(pipefd) == -1)
		error_exit("pipe", pipefd, in_or_out[0], in_or_out[1]);
	proc_cmd(pipefd, in_or_out, argv, envp);
	return (0);
}
