/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-15 08:46:59 by mignavar          #+#    #+#             */
/*   Updated: 2024-05-15 08:46:59 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include "./libft/libft.h"

# define READ 0
# define WRITE 1
# define IN 0
# define OUT 1
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define END "\033[0m"

void	close_fds(int fd[2]);
void	close_pipe(int extreme[2]);
void	close_std(void);
void	error_exit(int extreme[2], int fd[2]);
char	*search_path(char *envp[]);
char	*search_route(char *command, char *envp[]);

#endif