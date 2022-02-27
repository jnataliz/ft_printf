/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:10:48 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/26 19:14:20 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_p(unsigned int n)
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

char	*ft_ptoa(unsigned long int n)
{
	int			c;
	char		*str1;
	char		*str;
	char		*digits;

	digits = "0123456789abcdef";
	c = ft_count_p(n);
	str1 = malloc(sizeof(*str1) * (c + 1));
	if (!str1)
		return (NULL);
	str1[c] = '\0';
	str = str1;
	while (c > 0)
	{
		str1[c - 1] = digits[(n % 16)];
		n = n / 16;
		c--;
	}
	return (str);
}
