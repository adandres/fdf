/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:53:39 by adandres          #+#    #+#             */
/*   Updated: 2018/09/08 14:30:05 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calc_sin_cos(t_map **maps)
{
	t_map	*map;

	map = *maps;
	map->mat.cosx = cos(map->mat.tx * P_I);
	map->mat.cosy = cos(map->mat.ty * P_I);
	map->mat.cosz = cos(map->mat.tz * P_I);
	map->mat.sinx = sin(map->mat.tx * P_I);
	map->mat.siny = sin(map->mat.ty * P_I);
	map->mat.sinz = sin(map->mat.tz * P_I);
}

int			calc_dx(int x, int y, int z, t_map **maps)
{
	t_map	*p;
	int		dx;

	p = *maps;
	dx = p->mat.cosy * (p->mat.sinz * y + p->mat.cosz * x) - p->mat.siny * z;
	return (dx);
}

int			calc_dy(int x, int y, int z, t_map **maps)
{
	t_map	*p;
	int		dy;

	p = *maps;
	dy = p->mat.sinx * (p->mat.cosy * z + p->mat.siny *
	(p->mat.sinz * y + p->mat.cosz * x)) + p->mat.cosx *
		(p->mat.cosz * y - p->mat.sinz * x);
	return (dy);
}

int			calc_dz(int x, int y, int z, t_map **maps)
{
	t_map	*p;
	int		dz;

	p = *maps;
	dz = p->mat.cosx * (p->mat.cosy * z + p->mat.siny *
	(p->mat.sinz * y + p->mat.cosz * x)) - p->mat.sinx *
		(p->mat.cosz * y - p->mat.sinz * x);
	return (dz);
}
