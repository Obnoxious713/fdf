/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:55:19 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 15:55:20 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

void        ft_matcpy(float source[4][4], float dest[4][4])
{
    int     i;
    int     j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            dest[i][j] = source[i][j];
    }
}

void        ft_mat_mult(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
    int     i;
    int     j;

    i = -1;
    while (++i < 4)
    {
		j = -1;
		while (++j < 4)
			dest[i][j] = mat1[i][0] * mat2[0][j] +
			mat1[i][1] * mat2[1][j] +
			mat1[i][2] * mat2[2][j] +
			mat1[i][3] * mat2[3][j];
    }
}

void 		ft_vect_mult_mat(t_3d *v, float mat[4][4], t_3d *d)
{
	float	x;
	float	y;
	float	z;

	x = v->x * mat[0][0] +
		v->y * mat[1][0] +
		v->z * mat[2][0] +
		mat[3][0];
	y = v->x * mat[0][1] +
		v->y * mat[1][1] +
		v->z * mat[2][1] +
		mat[3][1];
	z = v->x * mat[0][2] +
		v->y * mat[1][2] +
		v->z * mat[2][2] +
		mat[3][2];
	d->x = x;
	d->y = y;
	d->z = z;
}
