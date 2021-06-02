/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:29:05 by adandres          #+#    #+#             */
/*   Updated: 2018/08/28 16:09:47 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_ligne1(t_map **maps)
{
	int		i;
	t_map	*map;

	map = *maps;
	i = 1;
	map->ligne.cumul = map->ligne.dy / 2;
	while (i <= map->ligne.dy)
	{
		map->ligne.y += map->ligne.yinc;
		map->ligne.cumul += map->ligne.dx;
		if (map->ligne.cumul >= map->ligne.dy)
		{
			map->ligne.cumul -= map->ligne.dy;
			map->ligne.x += map->ligne.xinc;
		}
		color_map_dy(i, &map);
		i++;
	}
}

void		print_ligne2(t_map **maps)
{
	int		i;
	t_map	*map;

	map = *maps;
	i = 1;
	map->ligne.cumul = map->ligne.dx / 2;
	while (i <= map->ligne.dx)
	{
		map->ligne.x += map->ligne.xinc;
		map->ligne.cumul += map->ligne.dy;
		if (map->ligne.cumul >= map->ligne.dx)
		{
			map->ligne.cumul -= map->ligne.dx;
			map->ligne.y += map->ligne.yinc;
		}
		color_map_dx(i, &map);
		i++;
	}
}

void		init_ligne(t_map **maps)
{
	t_map	*map;

	map = *maps;
	map->ligne.dx = map->ligne.x1 - map->ligne.x;
	map->ligne.dy = map->ligne.y1 - map->ligne.y;
	map->ligne.xinc = (map->ligne.dx > 0) ? 1 : -1;
	map->ligne.yinc = (map->ligne.dy > 0) ? 1 : -1;
	map->ligne.dx = (map->ligne.dx > 0) ? map->ligne.dx : -map->ligne.dx;
	map->ligne.dy = (map->ligne.dy > 0) ? map->ligne.dy : -map->ligne.dy;
}

void		print_ligne(t_map **maps)
{
	t_map	*map;

	map = *maps;
	init_ligne(&map);
	if (is_in_screen(map))
		map->img.data[map->ligne.y * map->width + map->ligne.x] =
			map->ligne.col;
	if (map->ligne.dx > map->ligne.dy)
		print_ligne2(&map);
	else
		print_ligne1(&map);
}

void		fill_ligne(int x, int y, int col, t_map **maps)
{
	t_map	*map;

	map = *maps;
	if (map->ligne.buffer == 0)
	{
		map->ligne.x = x;
		map->ligne.y = y;
		map->ligne.col = col;
		map->ligne.buffer++;
	}
	else
	{
		map->ligne.x1 = x;
		map->ligne.y1 = y;
		map->ligne.col1 = col;
		print_ligne(&map);
		map->ligne.buffer = 0;
	}
}
