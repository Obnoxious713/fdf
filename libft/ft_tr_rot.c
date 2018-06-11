/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tr_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:16:31 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/04 16:16:33 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tr_rot(int matrix[4][4], int ax, int ay, int az)
{
	int			xmat[4][4];
	int			ymat[4][4];
	int			zmat[4][4];

	xmat[0][0]=1;        xmat[0][1]=0;        xmat[0][2]=0;        xmat[0][3]=0;
	xmat[1][0]=0;        xmat[1][1]=COS(ax);  xmat[1][2]=SIN(ax);  xmat[1][3]=0;
	xmat[2][0]=0;        xmat[2][1]=-SIN(ax); xmat[2][2]=COS(ax);  xmat[2][3]=0;
	xmat[3][0]=0;        xmat[3][1]=0;        xmat[3][2]=0;        xmat[3][3]=1;

	ymat[0][0]=COS(ay);  ymat[0][1]=0;        ymat[0][2]=-SIN(ay); ymat[0][3]=0;
	ymat[1][0]=0;        ymat[1][1]=1;        ymat[1][2]=0;        ymat[1][3]=0;
	ymat[2][0]=SIN(ay);  ymat[2][1]=0;        ymat[2][2]=COS(ay);  ymat[2][3]=0;
	ymat[3][0]=0;        ymat[3][1]=0;        ymat[3][2]=0;        ymat[3][3]=1;

	zmat[0][0]=COS(az);  zmat[0][1]=SIN(az);  zmat[0][2]=0;        zmat[0][3]=0;
	zmat[1][0]=-SIN(az); zmat[1][1]=COS(az);  zmat[1][2]=0;        zmat[1][3]=0;
	zmat[2][0]=0;        zmat[2][1]=0;        zmat[2][2]=1;        zmat[2][3]=0;
	zmat[3][0]=0;        zmat[3][1]=0;        zmat[3][2]=0;        zmat[3][3]=1;

	ft_matmult(matrix, ymat, mat1);
	ft_matmult(mat1, xmat, mat2);
	ft_matmult(mat2, zmat, matrix);
}
