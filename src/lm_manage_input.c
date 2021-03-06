/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manage_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:17:06 by galemair          #+#    #+#             */
/*   Updated: 2018/09/24 16:33:18 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_input(t_input *input)
{
	t_input	*tmp;

	while (input)
	{
		tmp = input;
		input = input->next;
		free(tmp->line);
		free(tmp);
	}
}

void	freeanddisplay_input(t_input *input)
{
	t_input	*tmp;

	while (input)
	{
		ft_printf("%s\n", input->line);
		tmp = input;
		input = input->next;
		free(tmp->line);
		free(tmp);
	}
}

int		get_line(char **line, t_input *input, int start)
{
	static t_input	*current_line;

	if (start)
		current_line = input;
	if (!current_line)
	{
		*line = NULL;
		return (0);
	}
	*line = current_line->line;
	current_line = current_line->next;
	return (1);
}

int		check_line_validity(char *str)
{
	if (*str == '#')
		;
	else if (lm_is_good_room(str) != -1)
		; 
	else if (lm_verif_tube(str) != -1)
		;
	else
		return (-1);
	return (1);
}

int		stock_input(t_input **input)
{
	t_input	*tmp;
	char	*line;
	int		ret;

	ret = 1;
	if ((*input = malloc(sizeof(t_input))) == NULL)
		return (-2);
	if (get_next_line(0, &((*input)->line)) == -1)
		return (-2);
	tmp = *input;
	while ((ret = get_next_line(0, &line)) == 1)
	{
		if ((tmp->next = malloc(sizeof(t_input))) == NULL)
			return (-2);
		if (ret == -1)
			return (-2);
		tmp = tmp->next;
		tmp->line = line;
		tmp->next = NULL;
		if (check_line_validity(line) == -1)
			return (-1);
	}

	return (1);
}
