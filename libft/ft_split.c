/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:13:10 by mignavar          #+#    #+#             */
/*   Updated: 2023/10/05 18:09:32 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	l;
	int	word;

	l = 0;
	word = 0;
	while (s[l] != '\0')
	{
		if (s[l] == c)
			l++;
		else if (s[l] != c && (s[l + 1] == c || s[l + 1] == '\0'))
		{
			l++;
			word++;
		}
		else
			l++;
	}
	return (word);
}

int	len_word(char const *s, int l, char c)
{
	int	len;

	len = 0;
	while (s[l] != c)
	{
		len++;
		l++;
	}
	return (len);
}

char	**fill(char const *s, char c, int len)
{
	int		l;
	int		word;
	char	**str;

	l = len;
	word = len_word(s, l, c);
	while (s[len] != c)
	{
		*str = ft_substr(s, l, word);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		l;
	int		j;
	int		count;
	int		word;
	char	**str;

	l = 0;
	j = 0;
	count = count_words(s, c);
	str = (char **)ft_calloc((count + 1), sizeof(char **));
	if (!s || !c)
		return (NULL);
	while (s[l] != '\0')
	{
		if (s[l] != c)
		{
			*str = fill(s, c, l);
			j++;
			str++;
			l = l + word;
		}
		l++;
	}
	return (str);
}
