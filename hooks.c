/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:57:29 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 16:57:30 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void 		key_hook_rotation(int keycode, t_data *d)
{
	if (keycode == KEY_EIGHT)
	 	d->xr += 0.01;
	else if (keycode == KEY_TWO)
		d->xr -= 0.01;
	else if (keycode == KEY_SIX)
		d->yr += 0.01;
	else if (keycode == KEY_FOUR)
		d->yr -= 0.01;
	else if (keycode == KEY_NINE)
		d->zr += 0.01;
	else if (keycode == KEY_SEVEN)
		d->zr -= 0.01;
}

static void 		key_hook_translation(int keycode, t_data *d)
{
	if (keycode == KEY_W)
		d->y_trans += 5;
	else if (keycode == KEY_S)
		d->y_trans -= 5;
	else if (keycode == KEY_A)
		d->x_trans += 5;
	else if (keycode == KEY_D)
		d->x_trans -= 5;
}

static void 		key_hook_scale(int keycode, t_data *d)
{
	if (keycode == KEY_PLUS)
		d->scale += 0.1;
	else if (keycode == KEY_MINUS)
		d->scale = fabs(d->scale - 0.1);
}

int					expose_hook(t_data *d)
{
	draw_reload(d);
	return (0);
}

int					key_hook(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	key_hook_rotation(keycode, d);
	key_hook_translation(keycode, d);
	key_hook_scale(keycode, d);
	draw_reload(d);
	return (0);
}
