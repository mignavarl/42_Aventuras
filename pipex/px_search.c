/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-03 12:26:47 by mignavar          #+#    #+#             */
/*   Updated: 2024-06-03 12:26:47 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_substr(envp[i], 1, ft_strlen(envp[i]));
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*search_route(char *command, char *envp[])
{
	char	*path;
	char	**route;
	int		i;

	path = search_path(envp);
	if (!path)
		return (NULL);
	route = ft_split(path, ':');
	free(path);
	i = 0;
	while (route[i])
	{
		path = ft_strjoin(route[i], "/");
		path = ft_strjoin(path, command);
		if (access(path, F_OK) == 0)
		{
			ft_free_double(route);
			return (path);
		}
		i++;
	}
	ft_free_double(route);
	return (NULL);
}
