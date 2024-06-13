/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-13 10:02:59 by mignavar          #+#    #+#             */
/*   Updated: 2024-06-13 10:02:59 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_father(t_data data, char **argv, char **envp)
{
	char	**command;

	command = ft_split(argv[4], ' ');
	close(data.extreme[WRITE]);
	data.pid = fork();
	if (data.pid < 0)
		error_exit(data.extreme, data.fd);
	if (data.pid == 0)
		execve(search_route(command[0], envp), command, envp);
	else
		waitpid(data.pid, NULL, 0);
	ft_free_double(command);
	close_fds(data.fd);
	close_pipe(data.extreme);
}

void	first_child(t_data data, char **argv, char **envp)
{
	char	**command;

	command = ft_split(argv[3], ' ');
	execve(search_route(command[0], envp), command, envp);
	ft_free_double(command);
	error_exit(data.extreme, data.fd);
}

void	executing_command(t_data data, char **argv, char **envp)
{
	data.pid = fork();
	dup2(data.fd[IN], STDIN_FILENO);
	close(data.fd[IN]);
	if (data.pid < 0)
		error_exit(data.extreme, data.fd);
	if (data.pid == 0)
		first_child(data, argv, envp);
	else
	{
		waitpid(data.pid, NULL, 0);
		first_father(data, argv, envp);
	}
	close_fds(data.fd);
	close_pipe(data.extreme);
}
