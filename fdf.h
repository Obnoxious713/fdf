/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:24:15 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/03 14:24:15 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** ------ LIBRARIES ------
*/
# include "libft/libft.h"
# include "ft_libgfx/minilibx_macos_sierra/mlx.h"
# include "libgfx/libgfx.h"
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>


/*
** ------ VARIABLES ------
*/
# define RED			0xFF2222
# define GREEN			0x22FF22
# define BLUE			0x2222FF
# define PURPLE			0xFF22FF
# define WHITE			0xFFFFFF
# define GREY			0xAAAAAA
# define DGREY			0x444444
# define AMETHYST		0x6C2DC7
# define G_APPLE		0x4CC417
# define B_ORCHID		0x1F45FC

/*
** KEYS
*/

# define KEY_ESC 53
# define KEY_SPACE 49

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_SCROLL_BUTTON 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2

# define KEY_ONE	83
# define KEY_TWO	84
# define KEY_THREE	85
# define KEY_FOUR	86
# define KEY_FIVE	87
# define KEY_SIX	88
# define KEY_SEVEN	89
# define KEY_EIGHT	91
# define KEY_NINE	92

# define KEY_PLUS   69
# define KEY_MINUS  78

/*
** ------ PUBLIC FUNCTIONS ------
*/
int					expose_hook(t_data *data);
int					key_hook(int keycode, t_data *data);
void				display_usage(char *av);
void 				display_controls(void);
void 				draw_map(t_data *data);
void 				setup_world(t_data *data);
void 				calc_aligned(t_data *data);
void 				draw_reload(t_data *data);
void 				init_draw(t_data *data);
int					check_fd(int fd, char *filename);
t_plot				*parse_file(char *filename);

#endif
