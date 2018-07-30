/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:57:37 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 16:57:38 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void 			draw_map(t_data *data)
{
	int			x;
	int			y;

	y = -1;
	while (++y < data->plot->height)
	{
		x = -1;
		while (++x < data->plot->width)
		{
			if (y < data->plot->height - 1)
				ft_3d_drawline(data, *data->plot->points[y][x]->aligned,
									*data->plot->points[y + 1][x]->aligned);
			if (x < data->plot->width - 1)
				ft_3d_drawline(data, *data->plot->points[y][x]->aligned,
									*data->plot->points[y][x + 1]->aligned);
		}
	}
}

void 			setup_world(t_data *data)
{
	int			x;
	int			y;
	float		global_mat[4][4];

	ft_make_identity_matrix(global_mat);
	ft_tr_translate(global_mat, -(data->plot->width / 2),
								-(data->plot->height / 2), 0);
	y = -1;
	while (++y < data->plot->height)
	{
		x = -1;
		while (++x < data->plot->width)
		{
			ft_vect_mult_mat(data->plot->points[y][x]->local, global_mat,
							data->plot->points[y][x]->world);
		}
 	}
}

void 			calc_aligned(t_data *data)
{
	int			x;
	int			y;
	float		global_mat[4][4];

	ft_make_identity_matrix(global_mat);
	ft_tr_rotate(global_mat, data->xr, data->yr, data->zr);
	ft_tr_scale(global_mat, (WINDOW_SIZE_X * data->scale) / data->plot->width,
					(WINDOW_SIZE_Y * data->scale) / data->plot->height, 0);
	ft_tr_translate(global_mat, (WINDOW_SIZE_X / 2) + data->x_trans,
					(WINDOW_SIZE_Y / 2) + data->y_trans, 0);
	y = -1;
	while (++y < data->plot->height)
	{
		x = -1;
		while (++x < data->plot->width)
		{
			ft_vect_mult_mat(data->plot->points[y][x]->world, global_mat,
							data->plot->points[y][x]->aligned);
			data->plot->points[y][x]->aligned->z = data->plot->points[y][x]->local->z;
		}
	}
}

void 			draw_reload(t_data *data)
{
	calc_aligned(data);
	data->img = mlx_new_image(data->mlx, WINDOW_SIZE_X + 100,
										WINDOW_SIZE_Y + 100);
	data->pixel_img = mlx_get_data_addr(data->img, &(data->bpp),
										&(data->s_line), &(data->endian));
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

void 			draw(t_data *data)
{
	data->xr = 0.07;
	data->yr = 0.07;
	data->zr = 0.07;
	data->scale = 0.5;
	data->x_trans = 0;
	data->y_trans = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "FDF");
	init_color_tab(data);
	setup_world(data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}
