/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:37:08 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/27 20:48:20 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/ft_flag.h"

int	ft_printf(const char *text, ...)
{
	va_list			ptr;
	int				i;
	int				x;
	struct s_flag	f;

	i = 0;
	x = 0;
	va_start(ptr, text);
	while (text[i] != '\0')
	{
		if (text[i] == '%')
		{
			f = parse_flag(text[++i]);
			x += exec_flag(f, ptr);
			i++;
		}	
		else
		{
			ft_putchar_fd(text[i++], 1);
			x++;
		}
	}
	return (x);
}
