/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:24:15 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/03 14:24:15 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_SIZE 500
# define IMG_SIZE 477
# include "ft_libgfx/minilibx_macos_sierra/mlx.h"
# include "libft/libft.h"

typedef struct s_2d
{
	int			x;
	int			y;
}				t_2d;

typedef struct s_3d
{
	int			x;
	int			y;
	int			z;
}				t_3d;

typedef struct s_vertex
{
	t_3d		local;
	t_3d		world;
	t_3d		aligned;
}				t_vertex;

#endif
