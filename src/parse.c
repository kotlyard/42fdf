/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <dkotlyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:44:27 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/10/11 17:26:24 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	check_str(char const *str)
{
	int i;
	int is_sign;

	is_sign = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			print_error("Invalid map. Aborting...");
		if (str[i] == '+' || str[i] == '-')
			is_sign += i == 0 && ft_strlen(str) != 1 ? 1 : 100;
	}
	if (is_sign > 1 || ft_strlen(str) > 7)
		print_error("Invalid coordinates. Aborting...");
}

t_vector		*set_vector_to_center(t_vector *vectors, t_data *fdf)
{
	int i;

	i = -1;
	while (++i < fdf->width)
	{
		vectors[i].x -= fdf->height / 2 * fdf->scale;
		vectors[i].y -= fdf->width / 2 * fdf->scale;
	}
	return (vectors);
}

int				set_scale(t_data *fdf)
{
	int scale;

	scale = 3;
	if (fdf->height < 30)
		return (30);
	while ((scale) * fdf->height < WINDOW_HEIGHT / 1.5)
		scale += 3;
	return (scale);
}

t_vector		*translate_str_to_vector(char *str, t_data *fdf, int x)
{
	t_vector	*res;
	char		**splited;
	int			i;

	res = (t_vector*)ft_memalloc(sizeof(t_vector) * (fdf->width + 1));
	splited = ft_strsplit(str, ' ');
	i = -1;
	while (splited[++i])
	{
		check_str(splited[i]);
		res[i].x = i;
		res[i].y = x;
		res[i].z = ft_atoi(splited[i]) * (-1);
	}
	res[i].y = -228;
	if (!x)
		fdf->width = i;
	else if (i != (int)fdf->width)
		print_error("Invalid map. Aborting");
	i = 0;
	while (splited[i])
		ft_strdel(&splited[i++]);
	free(splited);
	return (res);
}

t_vector		**get_vectors(t_data *fdf)
{
	int			i;
	t_vector	**vectors;

	fdf->scale = set_scale(fdf);
	fdf->margin_y = 0;
	fdf->margin_x = 0;
	fdf->color = 0xFFFFFF;
	i = -1;
	vectors = (t_vector**)ft_memalloc(sizeof(t_vector*) * (fdf->height + 1));
	while (fdf->map[++i])
		vectors[i] = translate_str_to_vector(fdf->map[i], fdf, i);
	vectors[i] = NULL;
	vectors = multiply_by_scale(vectors, fdf);
	return (vectors);
}
