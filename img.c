/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:21:57 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/13 15:21:58 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// void 			put_img_square(t_mlx *mlx)
// {
// 	t_img		img;
// 	t_iterator	i;
//
// 	mlx_clear_window(mlx->mlx, mlx->win);
// 	img = mlx->img;
// 	img.img = mlx_new_image(mlx->mlx, 100, 100);
// 	img.data = (int*)mlx_get_data_addr(img.img, &img.bpp,
// 					&img.line_size, &img.endian);
// 	img.bpp /= 8;
// 	i.i = 0;
// 	i.y = -1;
// 	while (++i.y < 100)
// 	{
// 		i.x = -1;
// 		while (++i.x < 100)
// 		{
// 			i.i = (i.x * 4) + (i.y + img.line_size);
// 			img.data[i.i++] = (char)255; // blue
// 			img.data[i.i++] = (char)255; // green
// 			img.data[i.i++] = (char)255; // redß
// 		}
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 50, 50);
// 	mlx_string_put(mlx->mlx, mlx->win, 10, 10, WHITE, "put_img");
// }

// void 			map_init(t_mlx *mlx)
// {
// 	mlx->map.rot_x = 5;
// 	mlx->map.rot_y = 0;
// 	mlx->map.move_x = 0;
// 	mlx->map.move_y = 0;
// 	set_scale(mlx);
// 	mlx->map.center_x = (WIN_WIDTH - (mlx->map.cols * mlx->map.scale)) / 2;
// 	mlx->map.center_y = (WIN_HEIGHT - (mlx->map.rows * mlx->map.scale)) / 2;
// 	mlx->map.z_height = 1;
// 	put_img_map(mlx);
// }
//
// void 			put_img_map(t_mlx *mlx)
// {
// 	int			i;
// 	t_vector	vect;
// 	t_vector	down;
//
// 	img_clear(mlx);
// 	i = -1;
// 	while (++i < (mlx->map.rows * mlx->map.cols))
// 	{
// 		vect = mlx->map.vectors[i];
// 		prep(*mlx, &vect);
// 		if (i < (mlx->map.rows * mlx->map.cols) - mlx->map.cols)
// 		{
// 			down = mlx->map.vectors[i + mlx->map.cols];
// 			prep(*mlx, &down);
// 			draw_line(mlx, vect, down);
// 			put_img_vector(mlx, down);
// 		}
// 		(i > 0 && mlx->map.cols != 0) ? draw_line(mlx, mlx->map.prev, vect) : 0;
// 		put_img_vector(mlx, vect);
// 		mlx->map.prev = vect;
// 	}
// 	if (mlx->mode == 1)
// 		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, OFF_X, OFF_Y);
// }
//
// void 			put_img_vector(t_mlx *mlx, t_vector vect)
// {
// 	int			i;
//
// 	if (mlx->mode == 1)
// 	{
// 		if (vect.x > mlx->img.width - 1 || vect.x < 1)
// 			return ;
// 		i = (vect.x) + ((vect.y) * mlx->img.width);
// 		if (i > (mlx->img.width * mlx->img.height) || i < 0)
// 			return ;
// 		mlx->img.data[i] = vect.color;
// 	}
// 	else
// 		mlx_pixel_put(mlx->mlx, mlx->win, vect.x, vect.y, vect.color);
// }
