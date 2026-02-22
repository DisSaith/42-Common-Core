/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:23:44 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/11 10:23:46 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_exit(char *error, int pipefd[2], int infile, int outfile)
{
	if (infile >= 0)
		close(infile);
	if (outfile >= 0)
		close(outfile);
	if (pipefd[0] >= 0)
		close(pipefd[0]);
	if (pipefd[1] >= 0)
		close(pipefd[1]);
	perror(error);
	exit(1);
}

int	check_arg(int argc, char *argv[])
{
	int	i;

	if (argc != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
		return (0);
	}
	i = 1;
	while (i < 5)
	{
		if (!argv[i] || argv[i][0] == '\0')
		{
			write(2, "Error: empty argument\n", 22);
			return (0);
		}
		i++;
	}
	return (1);
}
