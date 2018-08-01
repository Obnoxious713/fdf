/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:57:33 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 16:57:34 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void 		clean(t_list **rows, char ***buf)
{
	t_list			*tmp;

	free((*rows)->content);
	tmp = *rows;
	*rows = (*rows)->next;
	free(tmp);
	ft_free_arr(*buf);
}

/*
**
*/

static t_plot 		*list_to_arr(t_plot *plot, t_list *rows)
{
	int				x;
	int				y;
	int				z;
	char			**buf;

	plot->points = (t_vertex***)ft_memalloc(sizeof(t_vertex**)
					* plot->height);
	y = -1;
	while (++y < plot->height)
	{
		plot->points[y] = (t_vertex**)ft_memalloc(sizeof(t_vertex*)
						* plot->width);
		buf = ft_strsplit(rows->content, ' ');
		x = -1;
		while (++x < plot->width)
		{
			z = ft_atoi(buf[x]);
			plot->points[y][x] = ft_make_vertex(x, y, z);
			plot->z_min = MIN(z, plot->z_min);
			plot->z_max = MAX(z, plot->z_max);
		}
		clean(&rows, &buf);
	}
	return (plot);
}

/*
**
*/

static t_plot 		*make_plot(void)
{
	t_plot			*plot;

	plot = (t_plot*)ft_memalloc(sizeof(t_plot));
	plot->width = -1;
	plot->z_min = -2147483648;
	plot->z_max = 2147483647;
	return (plot);
}

/*
**
*/

int					check_fd(int fd, char *filename)
{
	if (fd < 0)
		ft_error(ft_strcat(filename, " doesn't exist"));
	return (1);
}

/*
**
*/

t_plot				*parse_file(char *filename)
{
	char			*buf;
	int				res;
	int				fd;
	t_list			*list;
	t_plot			*plot;

	fd = open(filename, O_RDONLY);
	list = NULL;
	plot = make_plot();
	while ((res = ft_gnl(fd, &buf)) && check_fd(fd, filename))
	{
		if (plot->width == -1)
			plot->width = ft_countword(buf, ' ');
		if (plot->width != ft_countword(buf, ' '))
			ft_error("Invalid Map");
		ft_lstapp(&list, ft_lstnew(buf, ft_strlen(buf) + 1));
		(plot->height)++;
		free(buf);
	}
	if (res < 0)
		ft_error_unknown();
	close(fd);
	return (list_to_arr(plot, list));
}
