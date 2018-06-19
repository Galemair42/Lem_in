/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:37:05 by jabt              #+#    #+#             */
/*   Updated: 2018/06/19 13:40:58 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

# define HASH_SIZE 128

typedef struct		s_sommet
{
	char				*name;
	int					distance;
	int					visited;
	struct s_adj_lst	*lst;
	struct s_sommet		*next;
	struct s_sommet		*queue;
}					t_sommet;

typedef struct	s_adj_lst
{
	char				*name;
	struct s_adj_lst	*next;
}				t_adj_lst;

typedef struct s_nb_child
{
	int			nb;
	t_sommet	*parent;
}				t_nb_child;

/*
** 	hashtable function
*/

int			lm_hash(char *str);
t_sommet	*lm_get_adress(char *str, t_sommet **sommet);
int			lm_add_hashmap(t_sommet **sommet, char *str);
int			lm_add_sommet(t_sommet **sommet, char *str);
int			lm_add_start_end(t_sommet **sommet, int index);
t_sommet	*lm_get_sommet(t_sommet **sommet, char *needle);
void		lm_free_hashtable(t_sommet **hashtab);
int			lm_nb_child(t_sommet **sommet, t_sommet *parent);
t_sommet	*lm_loneliest_node(t_sommet *parent, t_sommet **sommet);

/*
 * 		adjencency lst function
 */

int			lm_add_tube(t_sommet **sommet, char *pattern);
void		lm_free_adj_lst(t_adj_lst *adj_lst);

/*
 * 		queue function
 */

t_sommet	*exit_queue(t_sommet **queue);
void		add_in_queue(t_sommet **queue, t_sommet *to_add);
void		lm_clear_all_queue(t_sommet **sommet);

/*
 * 		algo
 */

void		lm_queue_neighbor(t_sommet *head, t_sommet **queue, t_sommet **sommet);
int			get_distance(t_sommet **sommet, t_sommet **queue);
int			lm_start_algo(t_sommet **sommet, int ants);
int			lm_find_path_core(t_sommet **sommet);

/*
 * 	parsing function
 */

int			lm_parse_ant(char *ligne);
int			lm_parse_digit(char *ligne);
int			lm_parseur(t_sommet **sommet);
int			lm_is_good_room(char *room);

/*
 * 	un peu d'utils
 */

char		*lm_get_room_name(char *str);
int			lm_verif_tube(char *str);

/*
 *	debug ou temporaire
 */

int			lm_add_start(t_sommet **sommet, char *str);
int			lm_add_end(t_sommet **sommet, char *str);
void		print_sommet(t_sommet *sommet);
void		print_hashtable(t_sommet **sommet);
void		print_all_hashtable(t_sommet **sommet);
void		print_all_hashtable_wdistance(t_sommet **sommet);
void		debug_queue(t_sommet **sommet);

#endif
