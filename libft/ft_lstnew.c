/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:19:52 by jnataliz          #+#    #+#             */
/*   Updated: 2021/02/13 16:56:34 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head =(t_list *)malloc(sizeof(t_list));
	if (!head)
		return(NULL);
	head->content = content;
	head->next = NULL;
	return(head);
}
