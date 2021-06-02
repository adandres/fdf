/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 00:21:26 by adandres          #+#    #+#             */
/*   Updated: 2018/09/05 14:35:52 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_read(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*pptr;
	char	*str;

	pptr = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = pptr;
		if (pptr == NULL)
		{
			if (!(pptr = ft_strcpy(ft_strnew(ft_strlen(buff)), buff)))
				return (NULL);
		}
		else if (!(pptr = ft_strjoin(str, buff)))
		{
			free(str);
			return (NULL);
		}
		free(str);
	}
	return (pptr);
}

t_map		*fill_map(t_map *map, char **tab)
{
	char	**s;

	map->ligne.y = 0;
	map->col.tmax = 0;
	map->col.tmin = 0;
	while (tab[map->ligne.y])
	{
		E = 0;
		if (!(s = ft_strsplit(tab[map->ligne.y], ' ')))
			return (free_map(map));
		while (s[E] && E < map->x)
		{
			map->map[map->ligne.y][E] = ft_atoi(s[E]);
			if (map->map[map->ligne.y][E] > map->col.tmax)
				map->col.tmax = map->map[map->ligne.y][E];
			if (map->map[map->ligne.y][E] < map->col.tmin)
				map->col.tmin = map->map[map->ligne.y][E];
			E++;
		}
		free_char_tab(&s);
		if (E != map->x)
			return (free_map(map));
		map->ligne.y++;
	}
	return (map);
}

t_map		*atoi_tab(char **tab, char **str)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))) || str == NULL)
	{
		if (!(str == NULL))
			free_char_tab(&str);
		return (NULL);
	}
	map->ligne.y = 0;
	map->x = 0;
	map->y = 0;
	while (str[map->x])
		map->x++;
	while (tab[map->y])
		map->y++;
	free_char_tab(&str);
	if (!(help_for_atoi_tab(&map)))
		return (NULL);
	map = fill_map(map, tab);
	return (map);
}

t_map		*read_input(int fd)
{
	char		**tab;
	char		*ptr;
	t_map		*p;

	if ((ptr = ft_read(fd)) == NULL)
	{
		ft_putstr("Memory allocation failed.\n");
		return (0);
	}
	if (!(tab = ft_strsplit(ptr, '\n')))
	{
		free(ptr);
		ft_putstr("Memory allocation failed.\n");
		return (0);
	}
	free(ptr);
	if (!(p = atoi_tab(tab, ft_strsplit(tab[0], ' '))))
	{
		ft_putstr("Map error.\n");
		free_char_tab(&tab);
		return (0);
	}
	free_char_tab(&tab);
	return (p);
}
