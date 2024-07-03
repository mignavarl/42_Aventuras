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

void	final_child(t_data data, char **argv, char **envp)
{
	int		pid;
	char	**command;
	char	*route;

	pid = fork();
	if (pid < 0)
		error_exit(NULL, NULL);
	if (pid == 0)
	{
		command = ft_split(argv[data.arg - 2], ' ');
		route = search_route(command[0], envp);
		execve(route, command, envp);
		free(route);
		ft_free_double(command);
		perror("Error final child");
		exit(1);
	}
	else
		waitpid(pid, NULL, 0);
}

void	child(char **argv, char **envp, int h)
{
	char	**command;
	char	*route;

	command = ft_split(argv[h], ' ');
	route = search_route(command[0], envp);
	execve(route, command, envp);
	free(route);
	ft_free_double(command);
	perror("Error child");
	exit(1);
}

void	loop_children(char **argv, char **envp, int h)
{
	int	pid;
	int	pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		error_exit(pipefd, NULL);
	if (pid == 0)
	{
		close(pipefd[READ]);
		dup2(pipefd[WRITE], STDOUT_FILENO);
		close(pipefd[WRITE]);
		child(argv, envp, h);
	}
	else
	{
		close(pipefd[WRITE]);
		dup2(pipefd[READ], STDIN_FILENO);
		close(pipefd[READ]);
		waitpid(pid, NULL, 0);
	}
}
