/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:39:21 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/13 14:39:22 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"


void			rot_z3d(double theta, t_mlx *mlx)
{
	double		sin_t;
	double		cos_t;
	int			n;
	int			x;
	int			y;
	int			*node;

	node = (int*)ft_memalloc(sizeof(*node));
	sin_t = sin(theta);
	cos_t = cos(theta);
	n = -1;
	while (++n < (mlx->map.rows * mlx->map.cols))
	{
		node[0] = mlx->map.vectors[n].x;
		node[1] = mlx->map.vectors[n].y;
		x = node[0];
		y = node[1];
		node[0] = (x * cos_t) - (y * sin_t);
		node[1] = (y * cos_t) + (x * sin_t);
	}
	free((void*)node);
}

void			rot_y3d(double theta, t_mlx *mlx)
{
	double		sin_t;
	double		cos_t;
	int			n;
	int			x;
	int			z;
	int			*node;

	node = (int*)ft_memalloc(sizeof(*node));
	sin_t = sin(theta);
	cos_t = cos(theta);
	n = -1;
	while (++n < (mlx->map.rows * mlx->map.cols))
	{
		node[0] = mlx->map.vectors[n].x;
		node[2] = mlx->map.vectors[n].z;
		x = node[0];
		z = node[2];
		node[0] = (x * cos_t) - (z * sin_t);
		node[2] = (z * cos_t) + (x * sin_t);
	}
	free((void*)node);
}

void			rot_x3d(double theta, t_mlx *mlx)
{
	double		sin_t;
	double		cos_t;
	int			n;
	int			z;
	int			y;
	int			*node;

	node = (int*)ft_memalloc(sizeof(*node));
	sin_t = sin(theta);
	cos_t = cos(theta);
	n = -1;
	while (++n < (mlx->map.rows * mlx->map.cols))
	{
		node[1] = mlx->map.vectors[n].y;
		node[2] = mlx->map.vectors[n].z;
		y = node[1];
		z = node[2];
		node[1] = (y * cos_t) - (z * sin_t);
		node[2] = (z * cos_t) + (y * sin_t);
	}
	free((void*)node);
}
