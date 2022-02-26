/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:56:58 by jnataliz          #+#    #+#             */
/*   Updated: 2021/01/25 17:19:41 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != s[0])
	{
		if (s[i] == (char)c)
			return (&((char*)s)[i]);
		i--;
	}
	if ((char)c == s[i])
		return (&((char *)s)[i]);
	return (NULL);
}
