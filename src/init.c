/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 23:05:12 by adandres          #+#    #+#             */
/*   Updated: 2018/08/28 16:13:47 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_zoom(t_map **maps)
{
	t_map	*p;

	p = *maps;
	while ((p->width = cos(30 * P_I) * calc_dx(p->x * p->i, 0, 0, &p) +
				cos(30 * P_I) * calc_dy(0, p->y * p->i, 0, &p)) < W)
		p->i += 0.1;
	while (!((p->height = sin(60 * P_I) * calc_dx(p->x * p->i, 0, 0, &p) +
					sin(60 * P_I) * calc_dy(0, p->y * p->i, 0, &p)) < 1000))
		p->i -= 0.1;
}

void	init_matrice(t_map **maps)
{
	t_map	*map;

	map = *maps;
	map->mat.tx = 240;
	map->mat.ty = 180;
	map->mat.tz = 135;
}

int		make_image(t_map **maps, int o)
{
	t_map	*map;

	map = *maps;
	if (o == 1)
		mlx_destroy_image(map->mlx, map->img.img_ptr);
	map->img.img_ptr = mlx_new_image(map->mlx, map->width, map->height);
	if (map->img.img_ptr == NULL)
		return (0);
	map->img.data = (int *)mlx_get_data_addr(map->img.img_ptr, &map->img.bpp,
			&map->img.size_l, &map->img.endian);
	return (1);
}

int		init_display(t_map *map)
{
	t_square	q;

	mlx_destroy_window(map->mlx, map->win);
	map->win =
		mlx_new_window(map->mlx, map->width + 400, map->height + 200, "fdf");
	if (map->win == NULL)
		return (0);
	q = assign_squar(1, 1, map->width + 400, 99);
	print_color_square(q, &map);
	q = assign_squar(1, map->height + 100, map->width + 400, map->height + 200);
	print_color_square(q, &map);
	q = assign_squar(1, 95, 200, map->height + 105);
	print_color_square(q, &map);
	q = assign_squar(map->width + 200, 95, map->width + 400, map->height + 105);
	print_color_square(q, &map);
	init_disp(&map);
	q = assign_squar(29, 604, 171, 646);
	print_it(q, map);
	print_string(20, 700, "INTERFACE COLOR", map);
	q = assign_squar(25, 750, 175, 800);
	print_color_square(q, &map);
	q = assign_squar(29, 754, 171, 796);
	print_it(q, map);
	return (1);
}

int		init(t_map **maps)
{
	t_map	*map;

	map = *maps;
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		return (0);
	map->ligne.buffer = 0;
	init_var(&map);
	map->tz_mov = 0;
	map->var = 0;
	map->col.col = 0;
	map->color = 0xffffff;
	map->l_b = 0;
	map->i_b = 0;
	map->l_col = 0xffffff;
	map->i_col = 0xffffff;
	map->win =
		mlx_new_window(map->mlx, map->width + 400, map->height + 200, "fdf");
	if (map->win == NULL)
		return (0);
	if (!(init_display(map)))
		return (0);
	if (!(make_image(&map, 0)))
		return (0);
	return (1);
}
