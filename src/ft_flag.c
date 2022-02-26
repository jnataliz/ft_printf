/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:48:04 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/26 16:14:01 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flag.h"
#include "ft_printf.h"
#include "libft.h"
#include "stdarg.h"
#include "ft_flag.h"

int	exec_flag_c(va_list ptr)
{
	ft_putchar_fd(va_arg(ptr, int), 1);
	return (1);
}

int	exec_flag_d_i(va_list ptr)
{
	int		z;
	char	*str;
	int		x;

	z = va_arg(ptr, int);
	ft_putnbr_fd(z, 1);
	str = ft_itoa(z);
	x = ft_strlen(str);
	free(str);
	return (x);
}

int	exec_flag_s(va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	exec_flag_x(va_list ptr, int z)
{
	int		x;
	int		y;
	char	*str1;

	x = va_arg(ptr, int);
	str1 = ft_xtoa(x, z);
	ft_putstr_fd(str1, 1);
	y = ft_strlen(str1);
	free(str1);
	return (y);
}

int	exec_flag_u(va_list ptr)
{
	unsigned int		x;
	int					y;
	char				*str1;

	x = va_arg(ptr, unsigned int);
	str1 = ft_uitoa(x);
	ft_putstr_fd(str1, 1);
	y = ft_strlen(str1);
	free(str1);
	return (y);
}

int	exec_flag_p(va_list ptr)
{
	int		x;
	int		y;
	char	*str1;

	x = va_arg(ptr, unsigned long int);
	str1 = ft_ptoa(x);
	y = ft_printf("0x%s", str1);
	free(str1);
	return (y);
}


