/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:49:31 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/10/21 18:46:15 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_wordlenght(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static int	ft_checknull(const char *s, char **res, char c, int i)
{
	res[i] = ft_substr(s, 0, ft_wordlenght(s, c));
	if (res[i] == NULL)
	{
		while (i >= 0)
		{
			free(res[i]);
			i--;
		}
		free(res);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		count;

	count = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		if (*s != 0)
		{
			if (ft_checknull(s, res, c, i))
				return (NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	res[i] = 0;
	return (res);
}
