/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enplus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 02:14:31 by adandres          #+#    #+#             */
/*   Updated: 2018/09/05 14:36:16 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_square		assign_squar(int a, int b, int c, int d)
{
	t_square	square;

	square.xo = a;
	square.yo = b;
	square.xf = c;
	square.yf = d;
	return (square);
}

int				help_for_atoi_tab(t_map **maps)
{
	t_map		*map;

	map = *maps;
	if (!(map->map = (int**)malloc(sizeof(int*) * (map->y))))
		return (0);
	while (map->ligne.y < map->y)
	{
		if (!(map->map[map->ligne.y++] = (int*)malloc(sizeof(int) * (map->x))))
		{
			map->y = map->ligne.y;
			free_map(map);
			return (0);
		}
	}
	return (1);
}
