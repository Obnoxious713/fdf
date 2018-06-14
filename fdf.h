/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:24:15 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/03 14:24:15 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** ------ LIBRARIES ------
*/
# include "ft_libgfx/minilibx_macos_sierra/mlx.h"
# include <math.h>

/*
** ------ VARIABLES ------
*/
# define BUF_SIZE		777
# define WIN_WIDTH 		400//1080
# define WIN_HEIGHT 	400//720
# define WIN_SIZE 		500
# define IMG_SIZE 		477
# define OFF_X			0
# define OFF_Y			0
# define ROT_DEGREES	5
# define MV_PIXELS		5
# define RED			0xFF2222
# define GREEN			0x22FF22
# define BLUE			0x2222FF
# define PURPLE			0xFF22FF
# define WHITE			0xFFFFFF
# define GREY			0xAAAAAA
# define DGREY			0x444444
# define AMETHYST		0x6C2DC7
# define G_APPLE		0x4CC417
# define B_ORCHID		0x1F45FC

/*
** ------ STRUCTS ------
*/
typedef struct		s_line
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				err2;
}					t_line;

typedef struct		s_img
{
	int				bpp;
	int				color_val;
	int				endian;
	int				line_size;
	void			*img;
	int				*data;
	int				width;
	int				height;
}					t_img;

typedef struct		s_vector
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				*color_change;
}					t_vector;

typedef struct		s_file
{
	char			**split_y;
	char			**split_x;
	char			*cont;
	char			*tmp;
	char			buf[BUF_SIZE + 1];
	int				fd;
	int				ret;
}					t_file;

typedef struct		s_iterator
{
	int				i;
	int				x;
	int				y;
	int				z;
}					t_iterator;

typedef struct		s_map
{
	t_vector		*vectors;
	t_vector		prev;
	int				rows;
	int				cols;
	int				scale;
	int				max_z;
	float			z_height;
	int				center_x;
	int				center_y;
	int				rot_x;
	int				rot_y;
	int				move_x;
	int				move_y;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			*file;
	t_img			img;
	t_map			map;
	int				shift;
	int				mode;
	int				color_on;
}					t_mlx;

/*
** ------ PUBLIC FUNCTIONS ------
*/
void			blg(int	x0, int y0, int x1, int y1, t_mlx *mlx);
void			vlg(int x, int y0, int y1, t_mlx *mlx);
void			hlg(int x0, int x1, int y, t_mlx *mlx);
void 			put_img_square(t_mlx *mlx);
void 			prep(t_mlx mlx, t_vector *vect);
void 			set_scale(t_mlx *mlx);
float			set_theta(int degrees);
void			set_color(t_vector *vect, t_map *map);
void 			map_set(t_mlx *mlx, t_file *file);
void 			set_vector(t_mlx *mlx, t_iterator *i, t_file *file);
void 			draw_line(t_mlx *mlx, t_vector start, t_vector end);
void 			set_up(t_mlx *mlx);
void 			check_err(int err, char *msg);
void 			img_clear(t_mlx *mlx);
void 			put_img_map(t_mlx *mlx);
void 			put_img_vector(t_mlx *mlx, t_vector vect);
void 			map_init(t_mlx *mlx);
void			read_file(t_mlx *mlx, t_file *file);
void			usage(void);
void			set_cord(t_mlx *mlx, t_file *file);
void 			draw(t_mlx *mlx);
void 			draw_c(t_mlx *mlx);
void 			connect_points(t_mlx *mlx);
// void			rot_z3d(double theta, t_mlx *mlx);
// void			rot_y3d(double theta, t_mlx *mlx);
// void			rot_x3d(double theta, t_mlx *mlx);
// int			b_line_gen(void *mlx_ptr, void *win_ptr, t_2d *cord, t_2d *points);
// int				b_line_gen(void *mlx_ptr, void *win_ptr, t_2d *end_points, t_2d *points);
// void			fdf(void *mlx_ptr, void *win_ptr);
// int 			key_event(int key, void *param);
// int 			mouse_event(int key, void *param);
// void			gfx_setup();

#endif
