/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:45:03 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/06 13:45:04 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void		blg(int	x0, int y0, int x1, int y1, t_mlx *mlx)
{
	t_line	line;
	int		err;
	int		e2;

	line.dx = fabs((float)x1 - x0);
	if (x0 < x1)
		line.sx = 1;
	else
		line.sy = -1;
	line.dy = fabs((float)y1 - y0);
	if (y0 < y1)
		line.sy = 1;
	else
		line.sy = -1;
	if (line.dx > line.dy)
		err = (line.dx)/2;
	else
		err = (-(line.dy))/2;
	while (x0 != x1 && y0 != y1)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, mlx->map.vectors->color);
		e2 = err;
		if (e2 > (-(line.dx)))
		{
			err -= line.dy;
			x0 += line.sx;
		}
		if (e2 < line.dy)
		{
			err += line.dx;
			y0 += line.sy;
		}
	}
}

void		vlg(int x, int y0, int y1, t_mlx *mlx)
{
	while (y0 != y1)
	{
		if (y0 < y1)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y0++, mlx->map.vectors->color);
		else if (y0 > y1)
			mlx_pixel_put(mlx->mlx, mlx->win, x, y0--, mlx->map.vectors->color);
	}
}

void		hlg(int x0, int x1, int y, t_mlx *mlx)
{
	while (x0 != x1)
	{
		if (x0 < x1)
			mlx_pixel_put(mlx->mlx, mlx->win, x0++, y, mlx->map.vectors->color);
		else if (x0 > x1)
			mlx_pixel_put(mlx->mlx, mlx->win, x0--, y, mlx->map.vectors->color);
	}
}


// int			b_line_gen(void *mlx_ptr, void *win_ptr, t_2d *cord, t_2d *points)
// {
// 	int		dx;
// 	int		dy;
// 	int		dy_2;
// 	int		dy_dx_2;
// 	int		d_upper;
// 	int		d_lower;
// 	int		m;
// 	int		b;
// 	int		*pk;
// 	// int		v_len;
// 	int		i;
// 	int		x;
// 	int		px1;
// 	int		py1;
// 	int		y;
//
// 	i = -1;
// 	px1 = cord[0].x;
// 	py1 = cord[0].y;
// 	dx = cord[1].x - cord[0].x;
// 	dy = cord[1].y - cord[0].y;
// 	dy_2 = (2 * dy) - dx;
// 	dy_dx_2 = (2 * dy) - (2 * dx);
// 	pk = (int*)ft_memalloc(sizeof(*pk));
// 	pk[0] = dy_2 - dx;
// 	mlx_pixel_put(mlx_ptr, win_ptr, px1, py1, 0xffffff);
// 	mlx_pixel_put(mlx_ptr, win_ptr, cord[1].x, cord[1].y, 0x0fffff);
// 	if (dx != 0)
// 		m = (dy / dx);
// 	else
// 		m = ((dy + 1) / (dx + 1));
// 	if (m < 1)
// 	{
// 		while (++i < dx)
// 		{
// 			b = (-1 * (m * px1)) + py1;
// 			y = (m * px1) + b;
// 			d_upper = y - py1;
// 			d_lower = (py1 + 1) - y;
// 			pk[i] = dx * (d_lower - d_upper);
// 			if (pk[i] < 0)
// 			{
// 				pk[i + 1] = pk[i] + dy_2;
// 			}
// 			else
// 			{
// 				pk[i + 1] = pk[i] + dy_dx_2;
// 				py1 += m;
// 			}
// 			px1 += m;
// 			mlx_pixel_put(mlx_ptr, win_ptr, px1, py1, 0xff00ff);
// 			mlx_pixel_put(mlx_ptr, win_ptr, dx + px1, dy + py1, 0x00ffff);
// 		}
// 	}
// 	else if (m > 1)
// 	{
// 		b = (-1 * (m * px1)) + py1;
// 		while (++i < dy)
// 		{
// 			// TODO: do the math to figure this out tomorrow
// 			x = (m * py1) + b;
// 			d_upper = x - px1;
// 			d_lower = (px1 + 1) - x;
// 			pk[i] = dy * (d_lower - d_upper);
// 			if (pk[i] < 0)
// 			{
// 				pk[i + 1] = pk[i] + ((2 * dx) - dy);
// 			}
// 			else
// 			{
// 				pk[i + 1] = pk[i] + ((2 * dx) - (2 * dy));
// 				px1 += m;
// 			}
// 			py1 += m;
// 			mlx_pixel_put(mlx_ptr, win_ptr, px1, py1, 0xcc00ff);
// 			mlx_pixel_put(mlx_ptr, win_ptr, dx + px1, dy + py1, 0x000fff);
// 		}
// 	}
// 	free(points);
// 	return (0);
// }
