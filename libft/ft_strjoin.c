/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:17:59 by jnataliz          #+#    #+#             */
/*   Updated: 2021/01/29 12:13:24 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x[2];
	char	*s3;
	size_t	i[2];

	i[0] = 0;
	i[1] = 0;
	if (!s1 || !s2)
		return (NULL);
	x[0] = ft_strlen(s1);
	x[1] = ft_strlen(s2);
	if (!(s3 = malloc((x[0] + x[1] + 1) * sizeof(char))))
		return (NULL);
	while (i[0] < x[0])
	{
		s3[i[0]] = s1[i[0]];
		i[0]++;
	}
	while (i[1] < x[1])
	{
		s3[i[0]] = s2[i[1]];
		i[1]++;
		i[0]++;
	}
	s3[i[0]] = '\0';
	return (s3);
}
