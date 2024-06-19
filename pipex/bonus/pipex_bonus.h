/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 13:16:23 by mignavar          #+#    #+#             */
/*   Updated: 2024-06-04 13:16:23 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"

# define READ 0
# define WRITE 1
# define IN 0
# define OUT 1

typedef struct	s_data
{
	int	fd[2];
	int	extreme[2];
	int	pid;
	int	arg;
}				t_data;

void	n_pipes_function(t_data data, char **argv, char **envp);
void	loop_children(t_data data, char **argv, char **envp);
void	child(t_data data, char **argv, char **envp, int h);
void	final_child(t_data data, char **argv, char **envp);
void	close_fds(int fd[2]);
void	close_pipe(int extreme[2]);
void	error_exit(int extreme[2], int fd[2]);
char	*search_path(char *envp[]);
char	*search_route(char *command, char *envp[]);
void	executing_command(t_data data, char **argv, char **envp);

#endif