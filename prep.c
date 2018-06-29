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

void 			check_err(int err, char *msg)
{
	if (err < 1)
	{
		ft_putstr("ERROR: ");
		ft_putendl(msg);
		exit(1);
	}
}

// void 			draw_line(t_mlx *mlx, t_vector start, t_vector end)
// {
// 	t_line		line;
//
// 	line.dx = abs(end.x - start.x);
// 	line.sx = start.x < end.x ? 1 : -1;
// 	line.dy = abs(end.y - start.y);
// 	line.sy = start.y < end.y ? 1 : -1;
// 	line.err = (line.dx > line.dy ? line.dx : line.dy) / 2;
// 	while (1)
// 	{
// 		put_img_vector(mlx, start);
// 		if (start.x == end.x && start.y == end.y)
// 			break ;
// 		line.err2 = line.err;
// 		if (line.err2 > -line.dx)
// 		{
// 			line.err -= line.dy;
// 			start.x += line.sx;
// 		}
// 		if (line.err2 < line.dy)
// 		{
// 			line.err += line.dx;
// 			start.y += line.sy;
// 		}
// 	}
// }
//
// void 			prep(t_mlx mlx, t_vector *vect)
// {
// 	float		theta;
// 	t_iterator	i;
//
// 	i.x = vect->x * mlx.map.scale;
// 	i.y = vect->y * mlx.map.scale;
// 	i.z = vect->z * (mlx.map.z_height * mlx.map.scale);
// 	mlx.color_on == 1 ? set_color(vect, &mlx.map) : 0;
// 	theta = set_theta(mlx.map.rot_y);
// 	vect->x = i.x * cos(theta) - i.z * sin(theta);
// 	vect->z = i.z * cos(theta) + i.x * sin(theta);
// 	theta = set_theta(mlx.map.rot_x);
// 	vect->y = i.y * cos(theta) - i.z * sin(theta);
// 	vect->z = i.z * cos(theta) + i.y * sin(theta);
// 	vect->x += mlx.map.move_x;
// 	vect->y += mlx.map.move_y;
// 	vect->x = mlx.map.center_x;
// 	vect->y = mlx.map.center_y;
// }
//
// void 			set_scale(t_mlx *mlx)
// {
// 	int			sx;
// 	int			sy;
//
// 	mlx->map.scale = 0;
// 	sx = (mlx->img.width - 200) / mlx->map.cols;
// 	sy = (mlx->img.height - 200) / mlx->map.rows;
// 	if (sx < sy)
// 		mlx->map.scale = sx / 2;
// 	else
// 		mlx->map.scale = sy / 2;
// 	mlx->map.scale == 0 ? mlx->map.scale = 1 : 0;
// }
//
// float			set_theta(int degrees)
// {
// 	float		radians;
//
// 	if (degrees == 0)
// 		return (0);
// 	radians = degrees * (M_PI / 180);
// 	return (radians);
// }
//
// void			set_color(t_vector *vect, t_map *map)
// {
// 	int			max_z;
// 	int			z;
//
// 	z = vect->z * (map->z_height * map->scale);
// 	max_z = map->scale * map->max_z;
// 	if (z >= max_z * 1.5)
// 		vect->color = RED;
// 	else if (z >= max_z)
// 		vect->color = 0xFF9922;
// 	else if (z == 0)
// 		vect->color = WHITE;
// 	else
// 		vect->color = DGREY;
// }
//
// void 			set_vector(t_mlx *mlx, t_iterator *i, t_file *file)
// {
// 	char		**val;
//
// 	val = ft_strsplit(file->split_x[i->i], ',');
// 	mlx->map.vectors[i->i].x = i->x;
// 	mlx->map.vectors[i->i].y = i->y;
// 	mlx->map.vectors[i->i].z = ft_atoi_base(file->split_x[i->x], 10);
// 	if (mlx->map.vectors[i->i].z > mlx->map.max_z)
// 		mlx->map.max_z = mlx->map.vectors[i->i].z;
// 	if (val[1])
// 		mlx->map.vectors[i->i].color = ft_atoi_base(val[1] + 2, 16);
// 	else
// 	{
// 		if (mlx->map.vectors[i->i].z == 0)
// 			mlx->map.vectors[i->i].color = AMETHYST;
// 		else
// 			mlx->map.vectors[i->i].color = PURPLE;
// 	}
// 	ft_free_arr((void**)val);
// }
//
// void 			map_set(t_mlx *mlx, t_file *file)
// {
// 	t_iterator	i;
//
// 	mlx->map.vectors = malloc(sizeof(t_vector) * (mlx->map.rows * mlx->map.cols));
// 	mlx->map.max_z = 0;
// 	i.i = 0;
// 	i.y = 0;
// 	while (file->split_y[i.y])
// 	{
// 		i.x = 0;
// 		file->split_x = ft_strsplit(file->split_y[i.y], ' ');
// 		while (file->split_x[i.x])
// 		{
// 			if (i.x >= mlx->map.cols)
// 				break ;
// 			set_vector(mlx, &i, file);
// 			free(file->split_x[i.x++]);
// 			i.i++;
// 		}
// 		if (i.x < mlx->map.cols)
// 			check_err(0, "map error: incorrect row sizes");
// 		free(file->split_x);
// 		i.y++;
// 	}
// 	ft_free_arr((void**)file->split_y);
// }
