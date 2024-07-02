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

	data.fd[IN] = open("/tmp/.heredoc",
			O_RDWR | O_TRUNC | O_APPEND | O_CREAT, 00644);
	data.fd[OUT] = open(argv[5], O_WRONLY | O_APPEND | O_CREAT, 00644);
	pipe(data.extreme);
	input = ft_calloc(1, sizeof(char));
	while (ft_strncmp(argv[2], input, (ft_strlen(input) - 1)) != 0)
	{
		input = get_next_line(0);
		if (ft_strncmp(argv[2], input, (ft_strlen(input) - 1)) == 0
			&& input[0] != '\n')
			break ;
		ft_putstr_fd(input, data.fd[IN]);
		free(input);
	}
	free(input);
	close(data.fd[IN]);
	data.fd[IN] = open("/tmp/.heredoc", O_RDWR);
	executing_command(data, argv, envp);
	unlink("/tmp/.heredoc");
}

void	n_pipes_function(t_data data, char **argv, char **envp)
{
	int	h;

	h = 2;
	data.fd[IN] = open(argv[1], O_RDONLY);
	data.fd[OUT] = open(argv[data.arg - 1],
			O_WRONLY | O_TRUNC | O_CREAT, 00644);
	dup2(data.fd[IN], STDIN_FILENO);
	close(data.fd[IN]);
	while (h < data.arg - 2)
	{
		loop_children(argv, envp, h);
		h++;
	}
	dup2(data.fd[OUT], STDOUT_FILENO);
	close(data.fd[OUT]);
	final_child(data, argv, envp);
}

int	main(int argc, char **argv, char *envp[])
{
	t_data	data;

	if (argc < 5)
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		here_doc_function(data, argv, envp);
	}
	else
	{
		data.arg = argc;
		n_pipes_function(data, argv, envp);
	}
	return (0);
}
