/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:55:27 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/06 13:55:28 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void		fdf(void *mlx_ptr, void *win_ptr)
{
	t_2d	*cord;
	t_2d	*points;

	cord = (t_2d*)ft_memalloc(sizeof(*cord));
	points = (t_2d*)ft_memalloc(sizeof(*points));
	cord[0].x = 67;
	cord[0].y = 77;
	cord[1].x = 97;
	cord[1].y = 67;
	b_line_gen(mlx_ptr, win_ptr, cord, points);
}

int 		key_event(int key, void *param)
{
	void	*i;

	i = param;
	ft_putstr("key ");
	ft_putstr(ft_itoa(key));
	ft_putendl(" pressed");
	return (0);
}

int 		mouse_event(int key, void *param)
{
	void	*i;

	i = param;
	ft_putstr("mouse ");
	ft_putstr(ft_itoa(key));
	ft_putendl(" pressed");
	return (0);
}

void		gfx_setup()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		itow;
	char	*str;

	str = "fdf";
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_SIZE, WIN_SIZE, "fdf");
	img_ptr = mlx_new_image(mlx_ptr, IMG_SIZE, IMG_SIZE);
	itow = mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, IMG_SIZE, IMG_SIZE);
	mlx_key_hook(win_ptr, *key_event, (void*)str);
	mlx_mouse_hook(win_ptr, *mouse_event, (void*)str);
	fdf(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}
