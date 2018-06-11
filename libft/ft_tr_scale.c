/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tr_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:16:26 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/04 16:16:27 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tr_scale(int matrix[4][4], int sx, int sy, int sz)
{
	int			mat1[4][4];
	int			smat[4][4];

	smat[0][0]=sx; smat[0][1]=0;  smat[0][2]=0;  smat[0][3]=0;
	smat[1][0]=0;  smat[1][1]=sy; smat[1][2]=0;  smat[1][3]=0;
	smat[2][0]=0;  smat[2][1]=0;  smat[2][2]=sz; smat[2][3]=0;
	smat[3][0]=0;  smat[3][1]=0;  smat[3][2]=0;  smat[3][3]=1;
	ft_matmult(matrix, smat, mat1);
	ft_matcpy(mat1, matrix);
}
