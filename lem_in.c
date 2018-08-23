/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/08/23 18:04:09 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int 		ret;
	int			ants;
	int i = 0;
	char		*ligne;
//	t_sommet	*sommet[HASH_SIZE];
	t_sommet	**resid_graph;


	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
	if ((ants = lm_parseur(sommet)) == -1)
	{
		write(1, "ERROR\n", 6);
		lm_free_hashtable(sommet);
		ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
		return (0);
	}
//	lm_fill_distance(sommet, ants);
	resid_graph = lm_copy_hashtable();
	while (lm_search_path_dfs(resid_graph))
	{
		lm_update_main_graph(sommet, resid_graph);// pas besoins de copier le prev
	}

	print_flow(sommet);

	// faire une procedure pour free mon graph de resid
	
	
	//  je dois ici :
	//  	clean les internes shortcut
	//  	compter le nombre de path
	//  	REFLECHI BIEN A TES STRUCTURE DE DONNES

	exit(5);
	lm_fill_distance(sommet, ants);


	lm_free_hashtable(sommet);
	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));

	return (0);
}
