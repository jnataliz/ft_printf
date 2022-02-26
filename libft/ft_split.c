/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:02:18 by jnataliz          #+#    #+#             */
/*   Updated: 2021/02/03 18:22:44 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	int		t;

	i = 0;
	t = 0;
	while (*s)
	{
		if (*s != c && !t)
		{
			t = 1;
			i++;
		}
		else if (*s == c)
			t = 0;
		s++;
	}
	return (i);
}

static	size_t	count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_free(char **p)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 2;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (t);
}

static	size_t	ft_write(size_t len, char **p, char const *s)
{
	size_t	t;

	t = 1;
	while (*p)
		p++;
	if ((*p = ft_calloc(len + 1, sizeof(**p))))
		ft_strlcpy(*p, s, len + 1);
	else
		t = ft_free(p);
	return (t);
}

char			**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	t;

	p = NULL;
	t = 0;
	if (s && (p = ft_calloc(count_words(s, c) + 1, sizeof(*p))))
	{
		i = 0;
		while (s[i] && t != 2)
		{
			if (s[i] != c && t == 0)
				t = ft_write(count(&s[i], c), p, &s[i]);
			else if (s[i] == c)
				t = 0;
			i++;
		}
		if (t == 2)
			p = NULL;
	}
	return (p);
}
