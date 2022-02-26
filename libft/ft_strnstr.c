/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:14:21 by jnataliz          #+#    #+#             */
/*   Updated: 2021/01/28 11:58:03 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str1, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*str1)
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == str1[j])
		{
			if (!str1[j + 1] && (i + j) < n)
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
