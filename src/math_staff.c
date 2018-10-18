/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_staff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <dkotlyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:35:19 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/10/10 20:41:44 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			round_float(double f)
{
	int res;

	res = f;
	if (f - res > 0.499)
		res++;
	return (res);
}

t_vector	rotate_z(t_vector vector, t_data *fdf)
{
	float x;
	float y;

	x = vector.x;
	y = vector.y;
	x = x * COS_45 - y * SIN_45;
	y = x * SIN_45 + y * COS_45;
	vector.x = round_float(x) + fdf->height / 2 * fdf->scale;
	vector.y = round_float(y) + fdf->width / 2 * fdf->scale;
	return (vector);
}

t_vector	rotate_y(t_vector vector, t_data *fdf)
{
	float x;
	float z;

	x = vector.x;
	z = vector.z;
	x = x * COS_30 + z * SIN_30;
	z = x * SIN_30 + z * COS_30;
	vector.x = round_float(x);
	vector.z = round_float(z);
	return (rotate_z(vector, fdf));
}

t_vector	rotate_x(t_vector vector, t_data *fdf)
{
	float y;
	float z;

	y = vector.y;
	z = vector.z;
	y = y * COS_30 + z * SIN_30;
	z = y * SIN_30 + z * COS_30;
	vector.y = round_float(y);
	vector.z = round_float(z);
	return (rotate_y(vector, fdf));
}

void		rotate(t_data *fdf)
{
	int i;
	int j;

	i = -1;
	while (fdf->vectors[++i])
	{
		j = -1;
		fdf->vectors[i] = set_vector_to_center(fdf->vectors[i], fdf);
		while (++j < fdf->width)
			fdf->vectors[i][j] = rotate_x(fdf->vectors[i][j], fdf);
	}
}
