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

void	second_child(t_data data, char **argv, char **envp)
{
	char	**command;

	command = ft_split(argv[4], ' ');
	dup2(data.extreme[READ], STDIN_FILENO);
	close(data.extreme[READ]);
	dup2(data.fd[OUT], STDOUT_FILENO);
	close(data.fd[OUT]);
	execve(search_route(command[0], envp), command, envp);
	ft_free_double(command);
	error_exit(data.extreme, data.fd);
}

void	first_father(t_data data, char **argv, char **envp)
{
	close(data.extreme[WRITE]);
	data.pid = fork();
	if (data.pid < 0)
		error_exit(data.extreme, data.fd);
	if (data.pid == 0)
		second_child(data, argv, envp);
	else
		waitpid(data.pid, NULL, 0);
	close_fds(data.fd);
	close_pipe(data.extreme);
}

void	first_child(t_data data, char **argv, char **envp)
{
	char	**command;

	command = ft_split(argv[3], ' ');
	dup2(data.extreme[WRITE], STDOUT_FILENO);
	close(data.extreme[WRITE]);
	dup2(data.fd[IN], STDIN_FILENO);
	close(data.fd[IN]);
	execve(search_route(command[0], envp), command, envp);
	ft_free_double(command);
	error_exit(data.extreme, data.fd);
}

void	executing_command(t_data data, char **argv, char **envp)
{
	data.pid = fork();
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
