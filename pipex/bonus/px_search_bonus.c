/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_search_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 13:23:02 by mignavar          #+#    #+#             */
/*   Updated: 2024-06-04 13:23:02 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_threejoin(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	str = ft_strjoin(tmp, s3);
	free(tmp);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

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
		path = ft_threejoin(route[i], "/", command);
		if (access(path, F_OK) == 0)
		{
			ft_free_double(route);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_double(route);
	return (NULL);
}
