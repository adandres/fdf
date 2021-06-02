/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:32:38 by adandres          #+#    #+#             */
/*   Updated: 2018/08/25 14:51:21 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_var(t_map **maps)
{
	t_map	*p;

	p = *maps;
	p->i = 0;
	p->w = 0;
	p->d = 0;
	p->j = 0.2;
	p->oc = 0;
	p->col.prev_x = 0;
	init_matrice(&p);
	calc_sin_cos(&p);
	init_zoom(&p);
}

char		*print_display(int a, char *str)
{
	char	*ptr;
	char	*pttr;

	if (!(ptr = ft_itoa(a)))
		return (NULL);
	if (!(pttr = ft_strjoin(str, ptr)))
	{
		free(ptr);
		return (NULL);
	}
	free(ptr);
	return (pttr);
}

void		print_string(int x, int y, char *str, t_map *map)
{
	mlx_string_put(map->mlx, map->win, x, y, map->i_col, str);
}

void		init_di(t_map *map)
{
	t_square	q;

	print_square(map->height + 105, map->height + 196, &map);
	print_string(50, 400, "MAP COLOR", map);
	q = assign_squar(25, 450, 175, 500);
	print_color_square(q, &map);
	q = assign_squar(29, 454, 171, 496);
	print_it(q, map);
	print_string(50, 550, "LINE COLOR", map);
	q = assign_squar(25, 600, 175, 650);
	print_color_square(q, &map);
	print_string(900, 40, "Alexis Dandres", map);
	print_string(50, 150, "MAP INFO", map);
}

void		init_disp(t_map **maps)
{
	t_map		*map;
	char		*str;

	map = *maps;
	if ((str = print_display(map->height, "height = ")))
		mlx_string_put(map->mlx, map->win, 30, 200, map->i_col, str);
	free(str);
	if ((str = print_display(map->width, "width = ")))
		mlx_string_put(map->mlx, map->win, 30, 230, map->i_col, str);
	free(str);
	if ((str = print_display(map->x, "x max = ")))
		mlx_string_put(map->mlx, map->win, 30, 260, map->i_col, str);
	free(str);
	if ((str = print_display(map->y, "y max = ")))
		mlx_string_put(map->mlx, map->win, 30, 290, map->i_col, str);
	free(str);
	if ((str = print_display(map->col.tmin, "z min = ")))
		mlx_string_put(map->mlx, map->win, 30, 320, map->i_col, str);
	free(str);
	if ((str = print_display(map->col.tmax, "z max = ")))
		mlx_string_put(map->mlx, map->win, 30, 350, map->i_col, str);
	free(str);
	init_di(map);
}
