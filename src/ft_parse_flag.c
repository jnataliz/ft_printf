/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:05:46 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/26 15:33:34 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flag.h"
#include "ft_printf.h"
#include "libft.h"
#include "stdarg.h"

struct s_flag	parse_flag(char c)
{
	struct s_flag	res;

	res.code = c;
	res.length = 1;
	return (res);
}

int	exec_flag_c(va_list ptr)
{
	ft_putchar_fd(va_arg(ptr, int), 1);
	return (1);
}

int	exec_flag(struct s_flag s, va_list	ptr)
{
	int	x;

	x = 0;
	if (s.code == 'c')
		x = exec_flag_c(ptr);
	else if (s.code == 'd' || s.code == 'i')
		x = exec_flag_d_i(ptr);
	else if (s.code == 's')
		x = exec_flag_s(ptr);
	else if (s.code == 'x' || s.code == 'X')
		x = exec_flag_x(ptr, (s.code == 'X'));
	else if (s.code == 'u')
		x = exec_flag_u(ptr);
	else if (s.code == 'p')
		x = exec_flag_p(ptr);
	else if (s.code == '%')
	{
		ft_putchar_fd('%', 1);
		x++;
	}
	return (x);
}
