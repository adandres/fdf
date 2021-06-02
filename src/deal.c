/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal.c                                          /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:49:47 by adandres          #+#    #+#             */
/*   Updated: 2018/09/05 16:53:03 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		deal_fdf3(t_map **maps, int x, int y)
{
	t_map	*p;
	int		xi;
	int		yi;
	int		col;
	int		z;

	p = *maps;
	z = p->map[y][x] * -p->j;
	if (p->var % 2 && p->col.col % 2)
		col = col_with_var((double)p->map[y][x], p);
	else if (p->col.col % 2)
		col = col_out_var((double)p->map[y][x], p);
	else
		col = p->color;
	x = (x - p->x / 2) * p->i;
	y = (y - p->y / 2) * p->i;
	xi = calc_dx(x, y, z, &p) - p->d + p->width / 2;
	yi = calc_dy(x, y, z, &p) - p->w + p->height / 2;
	if ((xi > -2 * p->i && xi < p->width + 2 * p->i && yi > -2 * p->i &&
				yi < p->height + 2 * p->i))
		fill_ligne(xi, yi, col, &p);
}

static void		deal_fdf2(t_map **maps, int x, int y)
{
	t_map	*map;

	map = *maps;
	deal_fdf3(&map, x, y);
	if (x + 1 < map->x)
		deal_fdf3(&map, x + 1, y);
	if (y + 1 < map->y)
	{
		if (x + 1 < map->x)
			deal_fdf3(&map, x, y);
		deal_fdf3(&map, x, y + 1);
	}
	map->ligne.buffer = 0;
}

void			deal_fdf(t_map **maps)
{
	t_map	*map;
	int		y;
	int		x;

	map = *maps;
	y = 0;
	map->ligne.buffer = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			deal_fdf2(&map, x, y);
			x++;
		}
		y++;
	}
}
