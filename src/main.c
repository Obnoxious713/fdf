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

#include "../includes/fdf.h"

#include <signal.h>

void		display_usage(char *av)
{
	ft_putendl("usage: ");
	ft_putstr(av);
	ft_putendl(" <MAP_FILE>");
	exit(1);
}

void		display_controls(void)
{
	ft_putendl("CONTROLS:\n\
Translation:\n\
	Y: Key: W, S\n\
	X: Key: A, D\n\
Rotation\n\
	X: Keypad: 2, 8\n\
	Y: Keypad: 4, 6\n\
	Z: Keypad: 7, 9\n\
Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -");
}

void		fuck_you(int fag)
{
	(void)fag;
}

int			main(int ac, char **av)
{
	t_data *data;

	if (ac == 2)
	{
		data = (t_data*)ft_memalloc(sizeof(t_data));
		if (!data)
			ft_error("ft_memalloc Error");
		data->plot = parse_file(av[1]);
		display_controls();
		signal(SIGABRT, fuck_you);
		draw(data);
	}
	else
		display_usage(av[0]);
	return (0);
}
