/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_family_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-07 10:13:08 by mignavar          #+#    #+#             */
/*   Updated: 2024-06-07 10:13:08 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(t_data data, char **argv, char **envp, int h)
{
	char	**command;

	command = ft_split(argv[h + 1], ' ');
	printf("Command: %s\n", command[0]);
	if (h != 1)
		dup2(data.extreme[READ], STDIN_FILENO);
	dup2(data.extreme[WRITE], STDOUT_FILENO);
	close_fds(data.fd);
	close_pipe(data.extreme);
	execve(search_route(command[0], envp), command, envp);
	ft_free_double(command);
	error_exit(data.extreme, data.fd);
}

void	final_child(t_data data, char **argv, char **envp)
{
	char	**command;

	command = ft_split(argv[data.arg - 2], ' ');
	printf("Final Command: %s\n", command[0]);
	dup2(data.extreme[READ], STDIN_FILENO);
	dup2(data.fd[OUT], STDOUT_FILENO);
	close_fds(data.fd);
	close_pipe(data.extreme);
	execve(search_route(command[0], envp), command, envp);
	ft_free_double(command);
	error_exit(data.extreme, data.fd);
}

void	loop_children(t_data data, char **argv, char **envp)
{
	int	h;

	h = 1;
	dup2(data.fd[IN], STDIN_FILENO);
	while (h < (data.arg - 3))
	{
		pipe(data.extreme);
		data.pid = fork();
		if (data.pid < 0)
			error_exit(data.extreme, data.fd);
		if (data.pid == 0)
			child(data, argv, envp, h);
		close(data.extreme[WRITE]);
		h++;
	}
	data.pid = fork();
	if (data.pid < 0)
		error_exit(data.extreme, data.fd);
	if (data.pid == 0)
		final_child(data, argv, envp);
	while(waitpid(-1, NULL, 0) != -1)
		continue ;
}
