/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_is_worth_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:19:40 by jabt              #+#    #+#             */
/*   Updated: 2018/09/12 11:49:01 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 	INPUT
** 	node jsute avant node de fin
*/

static void		lm_count_length_path(t_sommet *node)
{
	int			ret;
	t_sommet	*tmp;

	ret = 0;
	tmp = node;
	while (node->prev)
	{
		ret++;
		node = node->prev;
	}
	tmp->distance = ret;
}

static int		lm_count_worthiness(t_sommet **graph, int worthiness,
		int ret, int path)
{
	int		tmp;

	if (!worthiness)
	{
		worthiness = (graph[1]->prev->distance - ret) + path + 1;
		return (worthiness);
	}
	else
	{
		tmp = (graph[1]->prev->distance - ret) - 1;
		if (tmp >= 0)
			worthiness = worthiness + ((tmp * path) + path + 1);
		else
			worthiness++;
		return (worthiness);
	}
}

/*
** 		INPUT
** 		hashtable avec le node du path qui vient
**		juste d'etre ajouter par mon bfs
*/

int				lm_is_worth_path_bfs(t_sommet **graph, int ants,
		int path)
{
	static int		ret;
	static int		worthiness;

	lm_count_length_path(graph[1]->prev);
	if (ret == 0)
	{
		if (ants > 0)
			ret = graph[1]->prev->distance;
		return (1);
	}
	else
	{
		worthiness = lm_count_worthiness(graph, worthiness, ret, path);
		ret = graph[1]->prev->distance;
		if (worthiness <= ants)
			return (1);
	}
	return (0);
}

/*
** 		OUTPOUT
** 		si le path est worth return 1
** 		sinon return 0 et enlever le path choisis car il n'est pas
** 		rentalbe
*/
