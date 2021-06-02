/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                         /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:53:27 by adandres          #+#    #+#             */
/*   Updated: 2018/09/04 19:15:40 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_c(int x, int y, t_map *map)
{
	int		p;
	int		xo;
	int		col;
	float	o;

	p = (map->width + 390) / 5;
	o = y - (map->height + 105);
	xo = x - 5;
	if (xo < p)
		col = RGB(o / 100 * (255 - xo * 255 / p), 0, o / 100 * xo * 255 / p);
	else if (xo < p * 2)
		col = RGB(0, o / 100 * ((xo - p) * 255 / p), o / 100 * 255);
	else if (xo < p * 3)
		col = RGB(0, o / 100 * 255, o / 100 * (255 - (xo - p * 2) * 255 / p));
	else if (xo < p * 4)
		col = RGB(o / 100 * ((xo - p * 3) * 255 / p), o / 100 * 255, 0);
	else
		col = RGB(o / 100 * 255, o / 100 * (255 - (xo - p * 4)
					* 255 / p + 1), 0);
	return (col);
}

int		deal_mouse(int button, int x, int y, t_map **maps)
{
	t_map		*map;
	t_square	q;

	map = *maps;
	if (button == 1 && x > 0 - 200 && y > 0 - 100 && x < map->width + 200 &&
			y < map->height + 100)
		fill_ligne(x - 200, y - 100, map->l_col, &map);
	else if (button == 1 && x > 5 && x <= map->width + 396 &&
			y > map->height + 105 && y <= map->height + 196)
	{
		if (map->l_b != 0)
			map->l_col = get_c(x, y, map);
		else if (map->i_b != 0)
			map->i_col = get_c(x, y, map);
		else
			map->color = get_c(x, y, map);
		init_display(map);
		q = assign_squar(x - 4, y - 4, x + 4, y + 4);
		print_color_square(q, &map);
		deal_fdf(&map);
	}
	mlx_hook_it(&map);
	return (0);
}

int		deal_key(int key, t_map **maps)
{
	t_map	*map;

	map = *maps;
	if (key == 53)
	{
		mlx_destroy_image(map->mlx, map->img.img_ptr);
		mlx_destroy_window(map->mlx, map->win);
		exit(1);
	}
	assign_key(key, &map);
	return (0);
}

int		test_mouse(int x, int y, t_map **maps)
{
	t_map *map;

	map = *maps;
	y = 0;
	if (map->tz_mov % 2 == 1)
	{
		if (x > map->col.prev_x)
			map->mat.tz = map->mat.tz % 360 + 1;
		else
			map->mat.tz = map->mat.tz % 360 - 1;
		if (!(make_image(&map, 1)))
			return (0);
		map->col.prev_x = x;
		calc_sin_cos(&map);
		deal_fdf(&map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 200, 100);
	}
	return (0);
}

void	mlx_hook_it(t_map **maps)
{
	t_map	*map;

	map = *maps;
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_ptr, 200, 100);
	mlx_mouse_hook(map->win, deal_mouse, &map);
	mlx_hook(map->win, 6, 0, test_mouse, &map);
	mlx_key_hook(map->win, deal_key, &map);
	mlx_loop(map->mlx);
	*maps = map;
}
