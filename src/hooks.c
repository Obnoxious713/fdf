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

#include "../libft/libft.h"

static void 		key_hook_rotation(int keycode, t_data *data)
{
	if (keycode == KEY_EIGHT)
	 	data->xr += 0.01;
	else if (keycode == KEY_TWO)
		data->xr -= 0.01;
	else if (keycode == KEY_SIX)
		data->yr += 0.01;
	else if (keycode == KEY_FOUR)
		data->yr -= 0.01;
	else if (keycode == KEY_NINE)
		data->zr += 0.01;
	else if (keycode == KEY_SEVEN)
		data->zr -= 0.01;
}

static void 		key_hook_translation(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->y_trans += 5;
	else if (keycode == KEY_S)
		data->y_trans -= 5;
	else if (keycode == KEY_A)
		data->x_trans += 5;
	else if (keycode == KEY_D)
		data->x_trans -= 5;
}

static void 		key_hook_scale(int keycode, t_data *data)
{
	if (keycode == KEY_PLUS)
		data->scale += 0.1;
	else if (keycode == KEY_MINUS)
		data->scale = fabs(data->scale - 0.1);
}

int					expose_hook(t_data *data)
{
	draw_reload(data);
	return (0);
}

int					key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_SPACE)
		expose_hook(data);
	key_hook_rotation(keycode, data);
	key_hook_translation(keycode, data);
	key_hook_scale(keycode, data);
	draw_reload(data);
	return (0);
}
