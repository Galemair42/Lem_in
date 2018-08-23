/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_hashtable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:05:59 by jabt              #+#    #+#             */
/*   Updated: 2018/08/20 14:38:13 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lm_free_hashtable(t_sommet **hashtab)
{
	int			i;
	t_sommet	*tmp;
	
	i = 0;
	while (i < HASH_SIZE)
	{

		if (hashtab[i])
		{
			tmp = hashtab[i];
			while (tmp)
			{
				free(tmp->name);
				if (tmp->lst)
				{
					lm_free_adj_lst(tmp->lst);
				}
				tmp = tmp->next;
				free(hashtab[i]);
				hashtab[i] = tmp;
			}
			hashtab[i] = NULL;
		}
		i++;
	}
}
