/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_staff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <dkotlyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:00:41 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/10/11 17:05:12 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_random_color(void)
{
	return (rand() % INT_MAX - 10000);
}

int		manage_keys(int key_id, t_data *fdf)
{
	if (key_id == 53)
		exit(0);
	if (key_id == 125)
		fdf->margin_y += fdf->scale;
	else if (key_id == 126)
		fdf->margin_y -= fdf->scale;
	else if (key_id == 124)
		fdf->margin_x += fdf->scale;
	else if (key_id == 123)
		fdf->margin_x -= fdf->scale;
	else if (key_id == 49)
		fdf->color = get_random_color();
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	fils_de_fer(fdf->vectors, fdf);
	return (0);
}

int		close_on_x(void *param)
{
	param = NULL;
	exit(0);
	return (0);
}

void	init_mlx_staff(t_data *fdf)
{
	srand(time(NULL));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
	WINDOW_HEIGHT, WINDOW_WIDTH, "fils de fer");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH);
}

void	draw_line(t_vector v1, t_vector v2, t_data *fdf, int color)
{
	const	int delta_x = abs(v2.x - v1.x);
	const	int delta_y = abs(v2.y - v1.y);
	const	int sign_x = v1.x < v2.x ? 1 : -1;
	const	int sign_y = v1.y < v2.y ? 1 : -1;
	t_error		error;

	error.er1 = delta_x - delta_y;
	while (v1.x != v2.x || v1.y != v2.y)
	{
		if (v1.y + fdf->margin_y >= 0 && v1.x + fdf->margin_x >= 0)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,
		(v1.x + fdf->margin_x), (v1.y + fdf->margin_y), color);
		error.er2 = error.er1 * 2;
		if (error.er2 > -delta_y)
		{
			error.er1 -= delta_y;
			v1.x += sign_x;
		}
		if (error.er2 < delta_x)
		{
			error.er1 += delta_x;
			v1.y += sign_y;
		}
	}
}
