/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:44:37 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/06 13:44:38 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void 		draw(t_mlx *mlx)
{
	// blg(mlx->map.vectors[0].x, mlx->map.vectors[0].y,
		// mlx->map.vectors[mlx->map.rows].x, mlx->map.vectors[mlx->map.cols].x, mlx);
	// vlg(77, 77, 177, mlx);
	// hlg(77, 177, 177, mlx);
	int		r;
	int		c;
	int		i;
	t_vector	*points;
	int		ii;
	int		iii;

	// points = (t_vector*)ft_memalloc(sizeof(*points) * 777);
	points = mlx->map.vectors;
	r = mlx->map.rows; // 20
	c = mlx->map.cols; // 11
	printf("%d, %d\n", r, c);
	i = -1;
	ii = -1;
	iii = -1;
	while (++ii < r)
	{
		i = -1;
		while (++i < r)
		{
			vlg(points[ii].x, points[i].y, points[i + 1].y, mlx);
		}
		//ii += 20;
	}
	i = -1;
	ii = 0;
	while (ii < c)
	{
		i = -1;
		while (++i < r)
		{
			hlg(points[i].x, points[i + 1].x, points[ii].y, mlx);
		}
		ii += 20;
	}
	//blg(points[0].x, points[r].x, points[0].y, points[c].y, mlx);
	// vlg(points[ii].x, points[i].y, points[c].y, mlx);
	// hlg(points[i].x, points[i + 1].x, points[ii].y, mlx);
	// vlg(points[ii].x, points[i].y, points[i + 1].y, mlx);
	//draw2(mlx, points);
}

// void 		draw2(t_mlx *mlx, t_vector *points)
// {
// 	int		c;
// 	int		i;
// 	int		ii;
//
// 	r = mlx->map.rows;
// 	c = mlx->map.cols;
// 	ii = -1;
// 	while (++ii < c)
// 	{
// 		i = -1;
// 		while (++i < r)
// 		{
// 			vlg(points[i].x, points[i].y, points[c].y, mlx);
// 		}
// 		// hlg(points[i].x, points[i + 1].x, points[ii].y, mlx);
// 		// vlg(points[ii].x, points[i].y, points[i + 1].y, mlx);
// 	}
// }


// char		**matrix_call(t_vector *vect)
// {
// 	char	**matrix;
// 	int		x;
// 	int		y;
// 	int		i;
//
// 	matrix = (char**)ft_memalloc(sizeof(**matrix));
// 	matrix[0] = "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0";
// 	matrix[1] = "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0";
// 	matrix[2] = "0  0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0";
// 	matrix[3] = "0  0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0";
// 	matrix[4] = "0  0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0";
// 	matrix[5] = "0  0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0";
// 	matrix[6] = "0  0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0";
// 	matrix[7] = "0  0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0";
// 	matrix[8] = "0  0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0";
// 	matrix[9] = "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0";
// 	matrix[10] = "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0";
// 	i = -1;
// 	y = -1;
// 	while (matrix[++y] != NULL)
// 	{
// 		x = -1;
// 		while (matrix[y][++x] != '\0')
// 		{
// 			vect[x].x = x;
// 			vect[y].y = y;
// 		}
// 		i++;
// 	}
// 	return (matrix);
// }

// void 		draw2(t_mlx *mlx)
// {
// 	int		*x;
// 	int		*y;
// 	int		i;
// 	int		yi;
// 	int		xi;
// 	int		xx;
// 	int		yy;
// 	char	**matrix;
// 	t_vector	*vect;
//
// 	vect = (t_vector*)ft_memalloc(sizeof(*vect));
// 	matrix = matrix_call(vect);
// 	i = 0;
// 	xi = -1;
// 	yi = -1;
// 	x = (int*)ft_memalloc(sizeof(*x));
// 	y = (int*)ft_memalloc(sizeof(*y));
// 	while (matrix[++yi] != NULL)
// 	{
// 		while (matrix[yi][++xi] != '\0')
// 		{
// 			y[i] = mlx->map.vectors[i].y;
// 			x[i] = mlx->map.vectors[i].x;
// 			xx = -1;
// 			yy = -1;
// 			// while (++yy < 277) // upper left v
// 			// 	mlx_pixel_put(mlx->mlx, mlx->win, x[i], y[i], RED);
// 			// while (++xx < 277) // top left h
// 			// 	mlx_pixel_put(mlx->mlx, mlx->win, x[i], y[i], PURPLE);
// 			draw(mlx);
// 			i++;
// 		}
// 	}
// }

void		set_cord(t_mlx *mlx, t_file *file)
{
	t_vector *points;
	int		r;
	int		c;
	int		i;
	char	**matrix;
	// char	*dd;

	points = (t_vector*)ft_memalloc(sizeof(*points) * 777);
	matrix = file->split_y;
	c = -1;
	i = -1;
	while (++c < mlx->map.cols)
	{
		r = -1;
		while (++r < mlx->map.rows)
		{
			points[++i].x = r * 17;
			points[i].y = c * 17;
			// if ((matrix[c][r] != ' ' && matrix[c][r] != '\n')
			// 	&& (matrix[c][r + 1] != ' ' && matrix[c][r + 1] != '\n'))
			// {
			// 		dd = &matrix[c][r];
			// 		ft_strcat(dd, &matrix[c][r + 1]);
			// }
			// printf("(%d, %d)\n\n", points[i].x, points[i].y);
		}
	}
	mlx->map.vectors = points;
}

int			key_pressed(int keycode, t_mlx *mlx)
{
	ft_putstr("key code: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(0);
	else if (keycode == 49)
		mlx_clear_window(mlx->mlx, mlx->win);
	else if (keycode == 1)
		mlx_string_put(mlx->mlx, mlx->win, 7, 7, DGREY, "fdf mlx 42");
	else
		ft_putendl("press 'space' to clear screen or 'esc' to exit");
	return (0);
}

int			mouse_clicked(int button, int x, int y, t_mlx *mlx)
{
	ft_putstr("button: ");
	ft_putstr(ft_itoa(button));
	ft_putstr("	x cord: ");
	ft_putstr(ft_itoa(x));
	ft_putstr("	y cord: ");
	ft_putendl(ft_itoa(y));
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		mlx_clear_window(mlx->mlx, mlx->win);
	draw(mlx);
	return (0);
}

void		read_file(t_mlx *mlx, t_file *file)
{
	int		i;

	if (!(file->fd = open(mlx->file, O_RDONLY)))
		exit(1);
	file->cont = (char*)ft_memalloc(sizeof(*file));
	while ((file->ret = read(file->fd, &file->buf, BUF_SIZE)))
	{
		file->buf[file->ret] = '\0';
		file->tmp = file->cont;
		file->cont = ft_strjoin(file->tmp, file->buf);
		free(file->tmp);
	}
	file->split_y = ft_strsplit(file->cont, '\n');
	file->split_x = ft_strsplit(file->split_y[0], ' ');
	i = -1;
	while (file->split_x[++i])
		free(file->split_x[i]);
	mlx->map.rows = i;
	i = 0;
	while (file->split_y[i])
		i++;
	mlx->map.cols = i;
	free(file->cont);
	free(file->split_x);
	set_cord(mlx, file);;
}

void		usage(void)
{
	ft_putendl("usage: ./fdf <MAP_FILE>");
	exit(1);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;
	t_file	file;

	if (ac != 2)
		usage();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx.file = av[1];
	file = *(t_file*)ft_memalloc(sizeof(file));
	read_file(&mlx, &file);
	mlx_string_put(mlx.mlx, mlx.win, 7, 7, DGREY, "fdf mlx 42");
	mlx_key_hook(mlx.win, key_pressed, &mlx);
	mlx_mouse_hook(mlx.win, mouse_clicked, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
