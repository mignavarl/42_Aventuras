/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:38:47 by mignavar          #+#    #+#             */
/*   Updated: 2023/11/08 17:17:59 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*appendix_read(char *buff, char *buff_read)
{
	char	*temp;

	temp = ft_strjoin(buff, buff_read);
	if (buff)
		free(buff);
	return (temp);
}

char	*read_file(char *buff, int fd)
{
	int		rd;
	char	*buff_read;

	buff_read = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff_read)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff_read, BUFFER_SIZE);
		if (rd == -1 || buff_read[0] == '\0')
		{
			free(buff_read);
			return (NULL);
		}
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		//buff = appendix_read(buff, buff_read);
		buff = ft_strjoin(buff, buff_read);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff_read);
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
	line = ft_calloc(l + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*rest_buff(char *buff)
{
	char	*temp;
	int		i;
	int		l;
	
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	l = i;
	while (buff[l] != '\0')
		l++;
	temp = ft_calloc(l + 1, sizeof(char));
	temp = &buff[i];
	free(buff);
	return (temp);
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

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("No se pudo abrir el archivo");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, line);
		free (line);
		line = NULL;
	}
	close(fd);
	return (0);
}
