/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <dkotlyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:49:02 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/10/11 17:08:06 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
************ INCLUDES ************
*/

# include <math.h>
# include <mlx.h>
# include <time.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"

/*
************ DEFINES ************
*/

# define WINDOW_HEIGHT 1500
# define WINDOW_WIDTH 1000
# define DEFAULT_SCALE 30
# define MARGIN 200
# define RET_ZERO(x) if (!(x)) return (0);

/*
**_____________ SINUS _____________
*/

# define SIN_0 0
# define SIN_15 0.2588
# define SIN_30 0.5
# define SIN_45 0.7071
# define SIN_60 0.866
# define SIN_75 0.9659
# define SIN_90 1
# define SIN_105 0.9659
# define SIN_120 0.866
# define SIN_135 0.7071
# define SIN_150 0.5
# define SIN_165 0.2588
# define SIN_180 0
# define SIN_195 (-2588)
# define SIN_210 (-0.5)
# define SIN_225 (-0.7071)
# define SIN_240 (-0.866)
# define SIN_255 (-0.9659)
# define SIN_270 (-1)

/*
**_____________ COSINUS _____________
*/

# define COS_0 1
# define COS_15 0.9659
# define COS_30 0.866
# define COS_45 0.7071
# define COS_60 0.5
# define COS_75 0.2588
# define COS_90 0
# define COS_105 (-0.2588)
# define COS_120 (-0.5)
# define COS_135 (-0.7071)
# define COS_150 (-0.866)
# define COS_165 (-0.9659)
# define COS_180 (-1)
# define COS_195 (-0.9659)
# define COS_210 (-0.866)
# define COS_225 (-0.7071)
# define COS_240 (-0.5)
# define COS_255 (-0.2588)
# define COS_270 0

/*
*********** STRUCTURES ************
*/

typedef struct		s_string
{
	char			*line;
	struct s_string	*next;
}					t_string;

typedef	struct		s_vector
{
	int				x;
	int				y;
	int				z;
}					t_vector;

typedef	struct		s_error
{
	int				er1;
	int				er2;
}					t_error;

typedef	struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				width;
	int				scale;
	int				margin_x;
	int				margin_y;
	int				color;
	int				height;
	int				len;
	char			**map;
	t_vector		**vectors;
	t_vector		**std_vectors;

}					t_data;

/*
**_______FUNCTIONS PROTOTYPES______
*/

/*
**__________ main.c __________
*/

void				fils_de_fer(t_vector **vectors, t_data *fdf);

/*
**__________ tools.c __________
*/

t_vector			**multiply_by_scale(t_vector **vectors, t_data *fdf);
void				print_error(char *msg);
t_vector			**copy_vectors(t_data *fdf);

/*
**__________ list_tools.c __________
*/

void				print_list(t_string *list);
void				add_to_list(char *line, t_string **list);
void				free_list(t_string *list);
char				**from_list_to_mas(t_string *list, int len);

/*
**__________ mlx_staff.c __________
*/

void				draw_line(t_vector v1, t_vector v2,
							t_data *data, int color);
void				init_mlx_staff(t_data *fdf);
int					manage_keys(int key_id, t_data *fdf);
int					get_random_color();
int					close_on_x(void *param);

/*
**__________ parse.c __________
*/

t_vector			**get_vectors(t_data *fdf);
t_vector			*set_vector_to_center(t_vector *vectors, t_data *fdf);

/*
**__________ math_staff.c __________
*/

t_vector			rotate_x(t_vector vector, t_data *fdf);
void				rotate(t_data *fdf);
int					round_float(double f);

#endif
