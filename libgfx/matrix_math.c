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

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include "libgfx.h"

/*
** ft_matcpy() takes two matrices and iterates through each element copying
** the values of 'source' into 'dest'
*/

void		ft_matcpy(float source[4][4], float dest[4][4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dest[i][j] = source[i][j];
	}
}

/*
** ft_mat_mult() takes three matrices and iterates though each element
** and multiplies them
*/

void		ft_mat_mult(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dest[i][j] = ((mat1[i][0] * mat2[0][j]) +
						(mat1[i][1] * mat2[1][j]) +
						(mat1[i][2] * mat2[2][j]) +
						(mat1[i][3] * mat2[3][j]));
	}
}

/*
** ft_vect_mult_mat() takes two vectors (t_3d) and a matrix. It sets the floats
** 'x', 'y', and 'z' to the sum of the values of each element in a column
** multiplied by the initial vectors x, y, and z values.
** It then sets the the second vectors x, y, and z values to 'x', 'y', and 'z'
*/

void		ft_vect_mult_mat(t_3d *vect, float mat[4][4], t_3d *data)
{
	float	x;
	float	y;
	float	z;

	x = ((vect->x * mat[0][0]) +
		(vect->y * mat[1][0]) +
		(vect->z * mat[2][0]) +
		mat[3][0]);
	y = ((vect->x * mat[0][1]) +
		(vect->y * mat[1][1]) +
		(vect->z * mat[2][1]) +
		mat[3][1]);
	z = ((vect->x * mat[0][2]) +
		(vect->y * mat[1][2]) +
		(vect->z * mat[2][2]) +
		mat[3][2]);
	data->x = x;
	data->y = y;
	data->z = z;
}
