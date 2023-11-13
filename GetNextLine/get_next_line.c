/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:38:47 by mignavar          #+#    #+#             */
/*   Updated: 2023/11/13 15:35:09 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*appendix_read(char *buff, char *buff_read)
{
	char	*temp;

	temp = ft_strjoin(buff, buff_read);
	free(buff);
	return (temp);
}

char	*read_file(char *buff, int fd)
{
	int		rd;
	char	*buff_read;

	rd = 1;
	while (rd > 0)
	{
		buff_read = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buff_read)
			return (NULL);
		rd = read(fd, buff_read, BUFFER_SIZE);
		if (rd == -1 || buff_read[0] == '\0')
		{
			free(buff_read);
			if (buff[rd] != '\0')
				return (buff);
			return (NULL);
		}
		buff = appendix_read(buff, buff_read);
		free(buff_read);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (buff);
}

char	*extract_line(char *buff)
{
	char	*line;
	int		i;
	int		l;

	l = 0;
	while (buff[l] != '\n' && buff[l] != '\0')
		l++;
	l++;
	line = ft_calloc(l + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[l - 1] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*rest_buff(char *buff)
{
	char	*temp;
	int		i;
	int		l;
	int		j;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	l = i;
	while (buff[l] != '\0')
		l++;
	temp = ft_calloc((l - i) + 1, sizeof(char));
	j = 0;
	while (buff[i] != '\0')
	{
		temp[j] = buff[i];
		i++;
		j++;
	}
	free(buff);
	return (temp); //Tengo que liberar el temp si lo que tiene es nada ¿Entonces que devolvería? ¿NULL quizás?
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_calloc(1, sizeof(char));
	if (!ft_strchr(buff, '\n'))
		buff = read_file(buff, fd);
	if (buff == '\0')
	{
		free(buff);
		return (NULL);
	}
	line = extract_line(buff);
	buff = rest_buff(buff);
	return (line);
}
