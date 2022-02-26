/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:34:44 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/25 00:19:03 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAG_H
# define FT_FLAG_H
# include <stdarg.h>

struct s_flag
{
	char	code;
	int		length;
};

struct s_flag	parse_flag(char c);
int				exec_flag(struct s_flag s, va_list	ptr);
int				exec_flag_c(va_list ptr);
int				exec_flag_d_i(va_list ptr);
int				exec_flag_s(va_list ptr);
int				exec_flag_x(va_list ptr, int z);
int				exec_flag_p(va_list ptr);
int				exec_flag_u(va_list ptr);

#endif