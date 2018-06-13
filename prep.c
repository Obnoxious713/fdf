/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:47:27 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/13 15:47:28 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void 			prep(t_mlx *mlx, t_vecotr *vect)
{
	float		theta;
	t_iterator	i;

	i.x = vect->x * mlx.map.scale;
	i.y = vect->y * mlx.map.scale;
	i.z = vect->z * (mlx.map.z_height * mlx.map.scale);
	mlx.color_on == 1 ? set_color(vect, &mlx.map) : 0;
	theta = set_theta(mlx.map.rot_y);
	vect->x = i.x * cos(theta) - i.z * sin(theta);
	vect->z = i.z * cos(theta) + i.x * sin(theta);
	theta = set_theta(mlx.map.rot_x);
	vect->y = i.y * cos(theta) - i.z * sin(theta);
	vect->z = i.z * cos(theta) + i.y * sin(theta);
	vect->x += mlx.map.move_x;
	vect->y += mlx.map.move_y;
	vect->x = mlx.map.center_x;
	vect->y = mlx.map.center_y;
}

void 			set_scale(t_mlx *mlx)
{
	int			sx;
	int			sy;

	mlx->map.scale = 0;
	sx = (mlx->img.width - 200) / mlx->map.cols;
	sx = (mlx->img.height - 200) / mlx->map.rows;
	if (sx < sy)
		mlx->map.scale = sx / 2;
	else
		mlx->map.scale = sy / 2;
	mlx->map.scale == 0 ? mlx->map.scale = 1 : 0
}

float			set_theta(int degrees)
{
	float		radians;

	if (degrees == 0)
		return (0);
	radians = degrees * (M_PI / 180;
	return (radians);
}

void			set_color(t_vector *vect, t_map *map)
{
	int			max_z;
	int			z;

	z = vect->z * (map->z_height * map->scale);
	max_z = map->scale * map->max_z;
	if (z >= map_z * 1.5)
		vect->color = RED;
	else if (z >= max_z)
		vect->color = 0xFF9922;
	else if (z == 0)
		vect->color = WHITE;
	else
		vect->color = DGREY;
}
