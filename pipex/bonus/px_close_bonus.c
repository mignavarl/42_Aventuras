/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 13:21:58 by mignavar          #+#    #+#             */
/*   Updated: 2024-06-04 13:21:58 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipe(int extreme[2])
{
	close(extreme[WRITE]);	
	close(extreme[READ]);
}

void	close_fds(int fd[2])
{
	if (fd[IN] == -1 || fd[OUT] == -1)
	{
		perror("Error");
		if (fd[IN] != -1)
			close(fd[IN]);
		if (fd[OUT] != -1)
			close(fd[OUT]);
		exit(0);
	}
	else
	{
		close(fd[IN]);
		close(fd[OUT]);
	}
}

void	error_exit(int extreme[2], int fd[2])
{
	close(extreme[WRITE]);
	close(extreme[READ]);
	close(fd[IN]);
	close(fd[OUT]);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	perror("Error");
	exit(0);
}
