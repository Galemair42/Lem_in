/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:37:05 by jabt              #+#    #+#             */
/*   Updated: 2018/08/25 19:05:46 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

# define HASH_SIZE 128

typedef struct		s_sommet
{
	char				*name;
	int					distance;
	int					ant;
	int					visited;//penser a utiliser visited partout comme
	//comme delimitateur
	//int					capacity;// surtout ne pas laisser ca
	struct s_adj_lst	*lst;
	struct s_sommet		*next;
	struct s_sommet		*prev;
}					t_sommet;

t_sommet	*sommet[HASH_SIZE];	

typedef struct	s_adj_lst
{
	char				*name;
	int					flow;
	struct s_adj_lst	*next;
}				t_adj_lst;

typedef struct	s_queue
{
	t_sommet		*sommet;
	struct s_queue	*next;
}				t_queue;

typedef struct	s_stack
{
	t_sommet		*sommet;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_control_queue
{
	t_queue		*head;
	t_queue		*tail;
}				t_control_queue;

typedef struct	s_shortcut
{
	t_sommet	*closer_node;
	t_sommet	*further_name;
}				t_shortcut;

/*
** 	hashtable function
*/

int			lm_hash(char *str);
t_sommet	*lm_get_adress(char *str, t_sommet **sommet);
int			lm_add_hashmap(t_sommet **sommet, char *str);
int			lm_add_sommet(t_sommet **sommet, char *str);
int			lm_add_start_end(t_sommet **sommet, int index);
t_sommet	*lm_get_sommet(t_sommet **sommet, char *needle);
t_sommet	**lm_copy_hashtable(void);
void		lm_free_hashtable(t_sommet **hashtab);
int			lm_nb_child(t_sommet **sommet, t_sommet *parent);
t_sommet	*lm_loneliest_node(t_sommet *parent, t_sommet **sommet);
t_sommet	*lm_copy_node(t_sommet *src);
t_sommet	*lm_double_node(t_sommet **sommet, t_sommet *dst, t_sommet *src);
int			lm_init_graph(t_sommet **sommet);
void		lm_update_main_graph(t_sommet **graph, t_sommet **resid_graph);

/*
 * 		adjencency lst function
 */

int			lm_add_tube(t_sommet **sommet, char *pattern);
void		lm_free_adj_lst(t_adj_lst *adj_lst);
int			lm_new_lst_node(t_adj_lst **lst, char *name, int flow);
int			lm_new_lst_node_atend(t_adj_lst **lst, char *name, int flow);

//void		lm_free_adj_lst_resid_graph(t_adj_lst *adj_lst);
//t_adj_lst	*lm_create_inlst(t_sommet **sommet, t_sommet *node);
//t_adj_lst	*lm_create_outlst(t_sommet **sommet, t_sommet *node);
//t_adj_lst	*lm_copy_lst(t_adj_lst *src);

/*
 * 		queue / stack function
 */

int			lm_add_elem_queue(t_control_queue *control, t_sommet *new_elem);
int			lm_add_elem_stack(t_stack **head, t_sommet *new_elem);
t_sommet	*lm_pop_queue(t_control_queue *control);
t_sommet	*lm_pop_stack(t_stack **head);


/*
t_sommet	*exit_queue(t_sommet **queue);
void		add_in_queue(t_sommet **queue, t_sommet *to_add);
void		lm_clear_all_queue(t_sommet **sommet);
*/
/*
 * 		algo
 */

int			lm_add_neighboor_bydist(t_sommet **sommet, t_sommet *node,
		t_control_queue *control_queue);
int			lm_add_neighboor(t_sommet **sommet, t_sommet *node,
		t_control_queue *control_queue);
int			lm_fill_distance(t_sommet **sommet, int ants);
void		lm_fill_distance_flow(t_sommet **graph);
int			lm_augmenting_path(t_sommet **sommet);
void		lm_sort_lst_byorder(t_sommet **sommet);
int			lm_sort_begin_byorder(t_sommet **sommet);
void		lm_update_flow(t_sommet **sommet);
void		lm_clean_visited(t_sommet **sommet);
t_adj_lst	*lm_get_edge(t_adj_lst *lst, char *str);
void		lm_init_neighboor_edge(t_sommet **sommet, t_sommet *node);
int			lm_find_max_flow(t_sommet **graph);
t_sommet	*lm_get_next_node_dfs(t_sommet **sommet, t_sommet *node);
int			lm_search_path_dfs(t_sommet **graph);
void		lm_print_ants(t_sommet **graph, int ants);

/*
 * 		display
 */

void		lm_print_ants(t_sommet **graph, int ants);

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

int			lm_add_start(t_sommet **hashtable, char *str);
int			lm_add_end(t_sommet **hashtable, char *str);
void		print_sommet(t_sommet *hashtable);
void		print_hashtable(t_sommet **hashtable);
void		print_all_hashtable(t_sommet **hashtable);
void		print_resid_graph(t_sommet **);
void		print_all_hashtable_wdistance(t_sommet **hashtable);
void		print_hashtable_distance_and_prev(t_sommet **hashtable);
void		debug_queue(t_sommet **hashtable);
void		print_path(t_sommet **hashtable, t_sommet *node);
void		print_queue(t_control_queue *control);
void		print_flow(t_sommet **hashtable);
void		print_node(t_sommet *);
void		print_adj_lst(t_sommet *, t_adj_lst *);
void		print_adj_lst_distance(t_sommet **, t_sommet *, t_adj_lst *);
void		print_hashtable_flow(t_sommet **hashtable);
void		print_stack(t_stack *stack);
void		print_ant_path(t_sommet **graph);

#endif
