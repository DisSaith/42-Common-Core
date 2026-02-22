/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:37:21 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/08 20:29:04 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

/***************FT_SPLIT***************/
int		is_strset(char c, char *strset);
int		count_words_strset(char *str, char *strset);
int		ft_strlen_strset(char *str, char *strset);
char	*ft_filltab_strset(char *str, char *strset);
char	**ft_split_strset(char *s, char *strset);

/***************ERRORS***************/
int		check_arg(int argc, char *argv[]);
void	error_exit(char *error, int pipefd[2], int infile, int outfile);

/***************UTILS***************/
int		open_fd(char *filename, int in_or_out, int infile);
void	*free_splited(char **tab);
void	closer(int pipefd[2], int infile, int outfile, int choice);
char	*find_path(char *envp[]);
char	*return_path_cmd(char *envp[], char *cmd);

/***************PIPEX***************/
void	cmd1(int pipefd[2], int infile, char *argv[], char *envp[]);
void	cmd2(int pipefd[2], int outfile, char *argv[], char *envp[]);
void	proc_cmd(int pipefd[2], int in_or_out[2], char *argv[], char *envp[]);

#endif
