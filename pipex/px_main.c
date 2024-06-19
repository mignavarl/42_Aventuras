/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-31 09:18:10 by mignavar          #+#    #+#             */
/*   Updated: 2024-05-31 09:18:10 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int fd[2], int extreme[2], char **argv, char **envp)
{
	char	**command;

	command = ft_split(argv[2], ' ');
	dup2(fd[IN], STDIN_FILENO);
	close(fd[IN]);
	dup2(extreme[WRITE], STDOUT_FILENO);
	close(extreme[WRITE]);
	if (execve(search_route(command[0], envp), command, envp) == -1)
	{
		ft_free_double(command);
		error_exit(extreme, fd);
	}
	ft_free_double(command);
	close(extreme[READ]);
	close(fd[OUT]);
}

void	second_child(int fd[2], int extreme[2], char **argv, char *envp[])
{
	char	**command;

	command = ft_split(argv[3], ' ');
	dup2(extreme[READ], STDIN_FILENO);
	close(extreme[READ]);
	dup2(fd[OUT], STDOUT_FILENO);
	close(fd[OUT]);
	if (execve(search_route(command[0], envp), command, envp) == -1)
	{
		ft_free_double(command);
		error_exit(extreme, fd);
	}
	ft_free_double(command);
	close(extreme[WRITE]);
	close(fd[IN]);
}

void	first_father(int fd[2], int extreme[2], char **argv, char *envp[])
{
	int	pid;

	close(extreme[WRITE]);
	pid = fork();
	if (pid < 0)
		error_exit(extreme, fd);
	else if (pid == 0)
		second_child(fd, extreme, argv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		close_fds(fd);
		close_pipe(extreme);
	}
}

void	init_family(int *fd, char **argv, char **envp)
{
	int	pid;
	int	extreme[2];

	pipe(extreme);
	pid = fork();
	if (pid < 0)
		error_exit(extreme, fd);
	if (pid == 0)
		first_child(fd, extreme, argv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		first_father(fd, extreme, argv, envp);
	}
	close_fds(fd);
	close_pipe(extreme);
}

int	main(int argc, char **argv, char *envp[])
{
	int	fd[2];

	if (argc != 5)
		return (0);
	fd[IN] = open(argv[1], O_RDONLY);
	if (fd[IN] == -1)
		close_fds(fd);
	fd[OUT] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd[OUT] == -1)
		close_fds(fd);
	init_family(fd, argv, envp);
	return (0);
}
