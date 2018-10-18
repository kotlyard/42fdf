/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <dkotlyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:33:15 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/10/11 20:22:20 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**read_map(int fd, t_data *data)
{
	char		*line;
	t_string	*list;
	int			ret;

	ret = 0;
	list = NULL;
	data->height = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!list)
			if (!(data->width = ft_strlen(line)))
				print_error("Invalid map");
		add_to_list(line, &list);
		ft_strdel(&line);
		data->height++;
	}
	ft_strdel(&line);
	if (ret == -1)
		print_error("Invalid file");
	return (from_list_to_mas(list, data->height));
}

int		check_fd_error(int ac, char **av)
{
	int fd;

	if (ac != 2)
		print_error("Usage: ./fdf file");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error("Open error");
	if (!ft_strstr(av[1], ".fdf"))
		print_error("Invalid file extension");
	return (fd);
}

void	fils_de_fer(t_vector **vectors, t_data *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (vectors[i + 1])
				draw_line(vectors[i + 1][j],
						vectors[i][j], fdf, fdf->color);
			if (vectors[i][j + 1].y != -228)
				draw_line(vectors[i][j + 1],
						vectors[i][j], fdf, fdf->color);
		}
	}
}

int		main(int ac, char **av)
{
	t_data	fdf;
	int		fd;

	fd = check_fd_error(ac, av);
	fdf.map = read_map(fd, &fdf);
	fdf.vectors = get_vectors(&fdf);
	init_mlx_staff(&fdf);
	rotate(&fdf);
	fils_de_fer(fdf.vectors, &fdf);
	mlx_hook(fdf.win_ptr, 17, 666, close_on_x, NULL);
	mlx_hook(fdf.win_ptr, 2, 666, manage_keys, &fdf);
	mlx_loop(fdf.mlx_ptr);
	close(fd);
	return (0);
}
