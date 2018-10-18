/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <dkotlyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:30:46 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/10/10 20:31:52 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_list(t_string *list)
{
	t_string *tmp;

	tmp = list;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

void	add_to_list(char *line, t_string **list)
{
	t_string			*new;
	static	t_string	*last;

	new = (t_string *)ft_memalloc(sizeof(t_string));
	new->line = ft_strdup(line);
	new->next = NULL;
	if (!*list)
		*list = new;
	else
		last->next = new;
	last = new;
}

void	free_list(t_string *list)
{
	t_string *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_strdel(&tmp->line);
		free(tmp);
	}
}

char	**from_list_to_mas(t_string *list, int len)
{
	char		**res;
	t_string	*tmp;
	int			i;

	i = 0;
	tmp = list;
	res = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	while (tmp)
	{
		res[i] = ft_strdup(tmp->line);
		tmp = tmp->next;
		i++;
	}
	res[i] = NULL;
	free_list(list);
	return (res);
}
