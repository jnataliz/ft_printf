/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:06:38 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/26 19:33:59 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(unsigned int n)
{
	int	c;

	c = 1;
	while (n >= 16)
	{
		n = n / 16;
		c++;
	}
	return (c);
}

char	*ft_xtoa(unsigned int n, int x)
{
	int			c;
	char		*str1;
	char		*str;
	char		*digits;

	if (x == 0)
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	c = ft_count(n);
	str1 = malloc(sizeof(*str1) * (c + 1));
	if (!str1)
		return (NULL);
	str = str1;
	str1[c] = '\0';
	while (c > 0)
	{
		str1[c - 1] = digits[(n % 16)];
		n = n / 16;
		c--;
	}
	return (str);
}
