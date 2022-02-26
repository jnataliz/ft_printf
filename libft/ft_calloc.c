/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:48:44 by jnataliz          #+#    #+#             */
/*   Updated: 2021/01/27 17:22:28 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *space;

	space = malloc(count * size);
	if (space == 0)
		return (space);
	ft_bzero(space, size * count);
	return (space);
}
