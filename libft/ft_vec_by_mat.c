/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_by_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:38:53 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/04 15:38:54 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 			ft_vec_by_mat(t_3D *destin, t_3d *source, int mat[4][4])
{
	destin->x = source->x * mat[0][0] +
				source->y * mat[1][0] +
				source->z * mat[2][0] +
							mat[3][0];
	destin->y = source->x * mat[0][0] +
				source->y * mat[1][0] +
				source->z * mat[2][0] +
					  		mat[3][0];
	destin->z = source->x * mat[0][0] +
				source->y * mat[1][0] +
				source->z * mat[2][0] +
							mat[3][0];
}
