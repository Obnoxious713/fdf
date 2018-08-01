/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:09:22 by jfleisch          #+#    #+#             */
/*   Updated: 2018/03/12 18:09:23 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				ft_lstadd(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}
