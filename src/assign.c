/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                        /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06:16:45 by adandres          #+#    #+#             */
/*   Updated: 2018/09/04 19:18:11 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		shifting_key(int k, t_map **maps)
{
	t_map	*map;

	map = *maps;
	if (k == 1)
		map->w += 25;
	if (k == 13)
		map->w -= 25;
	if (k == 0)
		map->d -= 50;
	if (k == 2)
		map->d += 50;
	if (k == 30)
		map->oc++;
	if (k == 33)
		map->oc--;
	if (k == 39)
		map->tz_mov++;
}

static void		other_key(int k, t_map **maps)
{
	t_map *map;

	map = *maps;
	if (k == 83)
	{
		map->i_b = 0;
		if (map->l_b != 0)
			map->l_b = 0;
		else
			map->l_b++;
	}
	if (k == 84)
	{
		map->l_b = 0;
		if (map->i_b != 0)
			map->i_b = 0;
		else
			map->i_b++;
	}
	if (k == 49)
		init_var(&map);
	if (k == 41)
		map->var++;
	if (k == 8)
		map->col.col++;
}

static void		zooming_key(int k, t_map **maps)
{
	t_map	*map;

	map = *maps;
	if (k == 126 && map->i < 1000)
	{
		map->i *= 1.05;
		map->d *= 1.05;
		map->w *= 1.05;
	}
	if (k == 125)
	{
		map->i *= 0.95;
		map->d *= 0.95;
		map->w *= 0.95;
	}
	if (k == 69)
		map->j += 0.2;
	if (k == 78)
		map->j -= 0.2;
}

static void		viewing_key(int k, t_map **maps)
{
	t_map	*map;

	map = *maps;
	if (k == 12)
		map->mat.tx = map->mat.tx % 360 + 2;
	if (k == 14)
		map->mat.tx = map->mat.tx % 360 - 2;
	if (k == 32)
		map->mat.ty = map->mat.ty % 360 + 2;
	if (k == 31)
		map->mat.ty = map->mat.ty % 360 - 2;
	if (k == 9)
		map->mat.tz = map->mat.tz % 360 + 2;
	if (k == 3)
		map->mat.tz = map->mat.tz % 360 - 2;
}

void			assign_key(int k, t_map **maps)
{
	t_map	*map;

	map = *maps;
	shifting_key(k, &map);
	viewing_key(k, &map);
	zooming_key(k, &map);
	other_key(k, &map);
	if (k == 258)
	{
		map->mat.tx = 0;
		map->mat.ty = 0;
		map->mat.tz = 0;
	}
	if (k != 83 && k != 84)
	{
		if (!(make_image(&map, 1)))
			return ;
		calc_sin_cos(&map);
		deal_fdf(&map);
		mlx_hook_it(&map);
	}
}
