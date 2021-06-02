/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:21:18 by adandres          #+#    #+#             */
/*   Updated: 2018/08/27 13:36:24 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_it(t_square q, t_map *map)
{
	int		j;
	int		i;

	i = q.yo;
	while (i < q.yf)
	{
		j = q.xo;
		while (j < q.xf)
		{
			if (q.yo == 454)
				mlx_pixel_put(map->mlx, map->win, j, i, map->color);
			if (q.yo == 604)
				mlx_pixel_put(map->mlx, map->win, j, i, map->l_col);
			if (q.yo == 754)
				mlx_pixel_put(map->mlx, map->win, j, i, map->i_col);
			j++;
		}
		i++;
	}
}

void		color_map_dy(int i, t_map **maps)
{
	t_map	*map;

	map = *maps;
	if ((is_in_screen(map) && i <= map->ligne.dy / 2 && map->ligne.col > 255) ||
			(map->ligne.col1 <= 255 && is_in_screen(map)))
		map->img.data[map->ligne.y * map->width + map->ligne.x] =
			map->ligne.col;
	else if (is_in_screen(map))
		map->img.data[map->ligne.y * map->width + map->ligne.x] =
			map->ligne.col1;
}

void		color_map_dx(int i, t_map **maps)
{
	t_map	*map;

	map = *maps;
	if ((is_in_screen(map) && i <= map->ligne.dx / 2 && map->ligne.col > 255) ||
			(map->ligne.col1 <= 255 && is_in_screen(map)))
		map->img.data[map->ligne.y * map->width + map->ligne.x] =
			map->ligne.col;
	else if (is_in_screen(map))
		map->img.data[map->ligne.y * map->width + map->ligne.x] =
			map->ligne.col1;
}
