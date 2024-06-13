/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 13:15:49 by mignavar          #+#    #+#             */
/*   Updated: 2024-06-04 13:15:49 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_function(t_data data, char **argv, char **envp)
{
	char	*input;

	data.fd[IN] = open(argv[1], O_TRUNC | O_APPEND | O_CREAT, 00644);
	data.fd[OUT] = open(argv[5], O_WRONLY | O_APPEND | O_CREAT, 00644);
	pipe(data.extreme);
	dup2(data.extreme[WRITE], STDOUT_FILENO);
	close(data.fd[OUT]);
	input = get_next_line(0);
	while (ft_strncmp(argv[2], input, ft_strlen(input)) != 0)
	{
		free(input);
		input = get_next_line(0);
	}
	free(input);
	printf("Antes executing\n");
	executing_command(data, argv, envp);
	unlink(argv[1]);
}

void	n_pipes_function(t_data data, char **argv, char **envp)
{
	data.fd[IN] = open(argv[1], O_RDONLY);
	data.fd[1] = open(argv[data.arg - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (data.fd[IN] == -1 || data.fd[OUT] == -1)
		close_fds(data.fd);
	loop_children(data, argv, envp);
	close_fds(data.fd);
	close_pipe(data.extreme);
	close_std();
}

int	main(int argc, char **argv, char *envp[])
{
	t_data	data;

	if (argc < 5)
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		printf("Entro heredoc\n");
		here_doc_function(data, argv, envp);//TODO: la funcion
	}
	else
	{
		printf("Entro n_pipe\n");
		data.arg = argc;
		n_pipes_function(data, argv, envp);
	}
	return (0);
}
