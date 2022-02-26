/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:04:09 by jnataliz          #+#    #+#             */
/*   Updated: 2021/01/29 12:14:32 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	x;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	x = ft_strlen(s);
	if ((x - start) < len && start < x)
		len = x - start;
	else if (start >= x)
		len = 0;
	s1 = malloc((len + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	while (start < x && i < len)
	{
		s1[i] = s[start];
		start++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
