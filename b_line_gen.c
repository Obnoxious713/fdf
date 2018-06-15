/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_line_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:44:05 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/05 12:44:06 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int				b_line_gen(void *mlx_ptr, void *win_ptr, t_2d *end_points, t_2d *points)
{
	int			y;
	int			dx;
	int			dy;
	int			dy_2;
	int			dy_dx_2;
	int			d_lower;
	int			d_upper;
	int			m;
	int			b;
	int			*pk;
	int			i;
	int			x;

	i = -1;
	y = 0;
	x = 0;
	points[0].x = end_points[0].x;
	points[0].y = end_points[0].y;
	dx = end_points[1].x - end_points[0].x;
	dy = end_points[1].y - end_points[0].y;
	dy_2 = (2 * dy) - dx;
	dy_dx_2 = (2 * dy) - (2 * dx);
	pk = (int*)ft_memalloc(sizeof(*pk));
	pk[0] = dy_2 - dx;
	mlx_pixel_put(mlx_ptr, win_ptr, points->x, points->y, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, dx + points->x, dy + points->y, 0x0000ff);
	if (dx != 0)
		m = (dy / dx);
	else
		m = 1;
	if (m < 1)
	{
		while (++i < dx)
		{
			b = (-1 * (m * points->x)) + points->y;
			y = (m * points->x) + b;
			d_upper = y - points->y;
			d_lower = (points->y + 1) - y;
			pk[i] = dx * (d_lower - d_upper);
			if (pk[i] < 0)
			{
				pk[i + 1] = pk[i] + dy_2;
			}
			else
			{
				pk[i + 1] = pk[i] + dy_dx_2;
				points->y++;
			}
			points->x++;
			mlx_pixel_put(mlx_ptr, win_ptr, points->x, points->y, 0xcc00ff);
			mlx_pixel_put(mlx_ptr, win_ptr, dx + points->x, dy + points->y, 0x000fff);
		}
	}
	else if (m > 1)
	{
		b = (-1 * (m * points->x)) + points->y;
		while (++i < dy)
		{
			// TODO: do the math to figure this out tomorrow
			x = (m * points->y) + b;
			d_upper = x - points->x;
			d_lower = (points->x + 1) - x;
			pk[i] = dy * (d_lower - d_upper);
			if (pk[i] < 0)
			{
				pk[i + 1] = pk[i] + ((2 * dx) - dy);
			}
			else
			{
				pk[i + 1] = pk[i] + ((2 * dx) - (2 * dy));
				points->x++;
			}
			points->y++;
			mlx_pixel_put(mlx_ptr, win_ptr, points->x, points->y, 0xcc00ff);
			mlx_pixel_put(mlx_ptr, win_ptr, dx + points->x, dy + points->y, 0x000fff);
		}
	}
	free(points);
	return (0);
}
