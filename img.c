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

void 			put_img_square(t_mlx *mlx)
{
	t_img		img;
	t_iterator	i;

	mlx_clear_window(mlx->mlx, mlx->win);
	img = mlx->img;
	img.img = mlx_new_image(mlx->mlx, 100, 100);
	img.data = (int*)mlx_get_data_addr(img.img, &img.bpp,
					&img.line_size, &img.endian);
	img.bpp /= 8;
	i.i = 0;
	i.y = -1;
	while (++i.y < 100)
	{
		i.x = -1;
		while (++i.x < 100)
		{
			i.i = (i.x * 4) + (i.y + img.line_size);
			img.data[i.i++] = (char)255; // blue
			img.data[i.i++] = (char)255; // green
			img.data[i.i++] = (char)255; // redß
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 50, 50);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, WHITE, "put_img");
}
