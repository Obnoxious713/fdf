/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:20:40 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/04 16:20:41 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIG_H
# define TRIG_H
int	sin_table[360];
int cos_table[360];
# define SIN(x) sin_table[ABS((int)x&359)]
# define COS(x) cos_table[ABS((int)x&359)]

#endif
