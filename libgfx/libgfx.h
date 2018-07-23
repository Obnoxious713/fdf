/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:55:38 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 15:55:39 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H
# include "../ft_libgfx/minilibx_macos_sierra/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# define COLOR1 0xa7f442
# define COLOR2 0xc542f4
# define WINDOW_SIZE_X 1000
# define WINDOW_SIZE_Y 700

typedef struct  s_2d
{
    short       x;
    short       y;
}               t_2d;

typedef struct	s_3d
{
	float		x;
	float		y;
	float		z;
}				t_3d;

typedef struct  s_vertex
{
    t_3d        *local;
    t_3d        *world;
    t_3d        *aligned;
}               t_vertex;

typedef struct  s_plot
{
    t_vertex    ***points;
    int         width;
    int         height;
    float       z_min;
    float       z_max;
}               t_plot;

typedef struct  s_data
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *pixel_img;
    float       xr;
    float       yr;
    float       zr;
    float       scale;
    float       x_trans;
    float       y_trans;
    int         bpp;
    int         s_line;
    int         endian;
    int         *colors;
    t_plot      *plot;
}               t_data;

t_3d            *ft_make_3d(int x, int y, int z);
t_vertex        *ft_make_vertex(int x, int y, int z);
void        	ft_matcpy(float source[4][4], float dest[4][4]);
void 	       	ft_mat_mult(float mat1[4][4], float mat2[4][4], float dest[4][4]);
void 			ft_vect_mult_mat(t_3d *v, float mat[4][4], t_3d *data);
void 			ft_make_identity_matrix(float matrix[4][4]);
void 			ft_tr_translate(float matrix[4][4], float tx, float ty, float tz);
void 			ft_tr_scale(float matrix[4][4], float sx, float sy, float sz);
void 			ft_tr_rotate(float matrix[4][4], float rx, float ry, float rz);
void 			init_color_tab(t_data *data);
void 			ft_3d_drawline(t_data *data, t_3d p0, t_3d p1);

#endif
