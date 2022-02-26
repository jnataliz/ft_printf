/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:49:39 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/24 23:42:46 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned int n)
{
	int	c;

	c = 1;
	while (n >= 10)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str1;
	char	*str;
	int		c;

	c = ft_count(n);
	str1 = malloc(sizeof(*str1) * (c + 1));
	if (!str1)
		return (NULL);
	str = str1;
	str1[c] = '\0';
	while (c > 0)
	{
		str1[c - 1] = ((n % 10) + '0');
		n = n / 10;
		c--;
	}
	return (str);
}
