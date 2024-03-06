/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garb_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:44:19 by mel-houd          #+#    #+#             */
/*   Updated: 2024/03/06 01:00:28 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void	clear_list(t_garb *list)
{
	t_garb	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		free(tmp->addr);
		list = list->next;
		free(tmp);
	}
}

void	add_node(t_garb **list, t_garb *node)
{
	t_garb	*head;

	if (!list || !node)
		return ;
	head = *list;
	node->next = NULL;
	if (!head)
	{
		*list = node;
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = node;
}

void	*gb_malloc(size_t size, int type)
{
	static t_garb	*list;
	t_garb			*node;
	void			*addr;

	if (type == 1)
		clear_list(list);
	else if (type == 0)
	{
		if (!(addr = malloc(size)))
		{
			clear_list(list);
			return (NULL);
		}
		if (!(node = malloc(sizeof(t_garb))))
		{
			clear_list(list);
			return (NULL);
		}
		node->addr = addr;
		add_node(&list, node);
		return (addr);
	}
	return (NULL);
}
