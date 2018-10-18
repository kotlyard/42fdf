/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <dkotlyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:32:05 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/10/11 17:07:20 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector		**copy_vectors(t_data *fdf)
{
	t_vector	**vectors;
	int			i;
	int			j;

	vectors = (t_vector**)ft_memalloc(sizeof(t_vector*) * (fdf->height + 1));
	i = -1;
	while (fdf->vectors[++i])
	{
		vectors[i] = (t_vector*)ft_memalloc(sizeof(t_vector)
					* (fdf->width + 1));
		j = -1;
		while (++j < fdf->width)
		{
			vectors[i][i].x = fdf->vectors[i][j].x;
			vectors[i][i].y = fdf->vectors[i][j].y;
			vectors[i][i].z = fdf->vectors[i][j].z;
		}
		vectors[i][j].y = -228;
	}
	vectors[i] = NULL;
	return (vectors);
}

t_vector		**multiply_by_scale(t_vector **vectors, t_data *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			vectors[i][j].x *= fdf->scale;
			vectors[i][j].y *= fdf->scale;
			vectors[i][j].z *= fdf->scale;
		}
	}
	return (vectors);
}

void			print_error(char *msg)
{
	ft_printf("[%s]\n", msg);
	exit(-1);
}
