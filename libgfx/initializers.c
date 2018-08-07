/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:55:08 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 15:55:09 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "libgfx.h"

/*
** ft_make_3d() takes cordinates of a vertex and creates a t_3d 'ret' whose
** x, y, and z values are then set to the args passed in
*/

t_3d			*ft_make_3d(int x, int y, int z)
{
	t_3d		*ret;

	ret = (t_3d*)ft_memalloc(sizeof(t_3d));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

/*
** ft_make_vertex() takes the cordinates of a vertex and sets the local value to
** the return value of ft_make_3d()
*/

t_vertex		*ft_make_vertex(int x, int y, int z)
{
	t_vertex	*ret;

	ret = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	ret->local = ft_make_3d(x, y, z);
	ret->world = ft_make_3d(0, 0, 0);
	ret->aligned = ft_make_3d(0, 0, 0);
	return (ret);
}
