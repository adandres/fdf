/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:21:29 by adandres          #+#    #+#             */
/*   Updated: 2018/04/20 20:15:33 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_add_link(t_list *list, void *content, size_t content_size)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = malloc(content_size);
		tmp->content = content;
		tmp->content_size = content_size;
		tmp->next = list;
	}
	return (tmp);
}
