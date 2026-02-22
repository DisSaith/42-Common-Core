/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:11:30 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/08 20:28:26 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*free_splited(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	open_fd(char *filename, int in_or_out, int infile)
{
	int		fd;

	if (in_or_out == 0)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			perror(filename);
	}
	if (in_or_out == 1)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
		{
			if (infile >= 0)
				close (infile);
			perror(filename);
			exit (1);
		}
	}
	return (fd);
}

void	closer(int pipefd[2], int infile, int outfile, int choice)
{
	if (choice == 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		if (infile >= 0)
			close(infile);
	}
	if (choice == 1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		close(outfile);
	}
	if (choice == 2)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		if (infile >= 0)
			close(infile);
		close(outfile);
	}
}

char	*find_path(char *envp[])
{
	size_t	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_strchr(envp[i], '/'));
		i++;
	}
	return (NULL);
}

char	*return_path_cmd(char *envp[], char *cmd)
{
	char	*path;
	char	**paths;
	char	*path_cmd;
	size_t	i;

	if (cmd[0] == '/')
		return (cmd);
	path = find_path(envp);
	paths = ft_split_strset(path, ":");
	i = 0;
	while (paths && paths[i])
	{
		path_cmd = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path_cmd, cmd);
		if (access(path_cmd, X_OK) == 0)
		{
			free_splited(paths);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	free_splited(paths);
	return (NULL);
}
