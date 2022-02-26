/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:31:42 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/19 17:37:28 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// #include <unistd.h>
//  ssize_t write(int fd, const void *buf, size_t count);
/*
ft_printf   : imita il comportamento della funzione printf 
text: contiene il testo da stampare e i flag per eventuali conversioni
... : parametri da convertire*/

int	ft_printf(const char *text, ...);
#endif