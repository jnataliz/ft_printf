/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:34:44 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/21 22:36:45 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	c;

	c = 1;
	if (n >= 0)
		n = n * -1;
	else
		c++;
	while (n <= -10)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str1;
	char	*str;
	int		c;

	c = ft_count(n);
	str1 = malloc(sizeof(*str1) * (c + 1));
	if (!str1)
		return (NULL);
	str = str1;
	if (n >= 0)
		n = n * -1;
	else
	{
		*str1++ = '-';
		c--;
	}
	str1[c] = '\0';
	while (c > 0)
	{
		str1[c - 1] = ((n % 10) * -1) + '0';
		n = n / 10;
		c--;
	}
	return (str);
}
