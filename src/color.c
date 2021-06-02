/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 01:05:11 by adandres          #+#    #+#             */
/*   Updated: 2018/08/28 16:09:57 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_square2(t_map *map, t_ligne l, float o)
{
	if (l.dx < l.x)
		mlx_pixel_put(map->mlx, map->win, l.dy, l.y,
		RGB(o / 100 * (255 - l.dx * 255 / l.x), 0, o / 100 * l.dx * 255 / l.x));
	else if (l.dx < l.x * 2)
		mlx_pixel_put(map->mlx, map->win, l.dy, l.y,
				RGB(0, o / 100 * ((l.dx - l.x) * 255 / l.x), o / 100 * 255));
	else if (l.dx < l.x * 3)
		mlx_pixel_put(map->mlx, map->win, l.dy, l.y,
		RGB(0, o / 100 * 255, o / 100 * (255 - (l.dx - l.x * 2) * 255 / l.x)));
	else if (l.dx < l.x * 4)
		mlx_pixel_put(map->mlx, map->win, l.dy, l.y,
			RGB(o / 100 * ((l.dx - l.x * 3) * 255 / l.x), o / 100 * 255, 0));
	else
		mlx_pixel_put(map->mlx, map->win, l.dy, l.y,
	RGB(o / 100 * 255, o / 100 * (255 - (l.dx - l.x * 4) * 255 / l.x + 1), 0));
}

void		print_square(int yo, int yf, t_map **maps)
{
	t_map		*map;
	t_ligne		l;
	float		o;

	map = *maps;
	l.x = (map->width + 390) / 5;
	l.x1 = (map->width + 396);
	l.y = yo;
	o = 0;
	while (l.y < yf)
	{
		l.dy = 5;
		l.dx = 1;
		while (l.dy++ < l.x1)
		{
			print_square2(map, l, o);
			l.dx++;
		}
		o++;
		l.y++;
	}
}

void		print_color_square(t_square q, t_map **maps)
{
	t_map		*map;
	int			i;
	int			j;

	map = *maps;
	j = q.yo;
	while (j < q.yf)
	{
		i = q.xo;
		while (i < q.xf)
		{
			if (i < q.xo + 5 || i > q.xf - 5 || j < q.yo + 5 || j > q.yf - 5)
				mlx_pixel_put(map->mlx, map->win, i, j, map->i_col);
			i++;
		}
		j++;
	}
}

int			col_with_var(double t, t_map *p)
{
	double		a;
	double		b;
	double		c;

	c = (p->col.tmax * 0.60);
	b = (p->col.tmax * 0.2);
	a = 180 / (p->col.tmax * 0.05);
	if (t <= p->oc)
	{
		if (p->col.tmin - p->oc != 0)
			return (RGB(0, 0, 255 - (t - p->oc) * 200 / (p->col.tmin - p->oc)));
		else
			return (RGB(0, 0, 255 - (t - p->oc) * 200));
	}
	else if (t < p->col.tmax * 0.02)
		return (RGB(255 - t * 230 / (p->col.tmax * 0.02), 255, 0));
	else if (t < p->col.tmax * 0.05)
		return (RGB(0, (255 - (t * a)), 0));
	else if (t < p->col.tmax * 0.2)
		return (RGB(210, 180 - t * 75 / b, 140 - t * 110 / b));
	else if (t < p->col.tmax * 0.60)
		return (RGB(210 - t * 82 / c, 105 - t * 105 / c, 30 - t * 30 / c));
	return (RGB(255, 230, 200));
}

int			col_out_var(double t, t_map *p)
{
	if (t <= p->oc)
		return (RGB(0, 0, 255));
	else if (t < p->col.tmax * 0.02)
		return (RGB(255, 255, 0));
	else if (t < p->col.tmax * 0.05)
		return (RGB(0, 255, 0));
	else if (t < p->col.tmax * 0.2)
		return (RGB(210, 180, 140));
	else if (t < p->col.tmax * 0.60)
		return (RGB(210, 105, 30));
	return (RGB(255, 230, 200));
}
