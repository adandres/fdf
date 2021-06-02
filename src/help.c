/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:31:09 by adandres          #+#    #+#             */
/*   Updated: 2018/09/05 14:35:57 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		is_in_screen(t_map *map)
{
	if (map->ligne.y < map->height && map->ligne.x < map->width &&
			map->ligne.y > 0 && map->ligne.x > 0)
		return (1);
	return (0);
}

char	**free_char_tab(char ***tab)
{
	char	**str;
	int		i;

	str = *tab;
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	*tab = str;
	tab = NULL;
	return (NULL);
}

t_map	*free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->y)
		free(map->map[i++]);
	free(map->map);
	free(map);
	return (NULL);
}
