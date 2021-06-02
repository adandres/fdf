/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                          /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:10:08 by adandres          #+#    #+#             */
/*   Updated: 2018/09/08 14:36:56 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		test_file(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr(str);
		ft_putstr(" is not a valid file.\n");
		return (0);
	}
	close(fd);
	return (1);
}

void	main2(t_map **maps)
{
	t_map *map;

	map = *maps;
	if (!(init(&map)))
	{
		ft_putstr("An issue occurred with mlx.h library.\n");
		return ;
	}
	deal_fdf(&map);
	mlx_hook_it(&map);
}

int		main(int ac, char **av)
{
	t_map	*map;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		ft_putstr("usage : ./fdf <filename>\n");
		return (0);
	}
	if (!(test_file(av[1])) || !(map = read_input(fd)))
		return (0);
	if (map->x == 0)
	{
		ft_putendl("error : map is empty");
		map = free_map(map);
		return (0);
	}
	main2(&map);
	close(fd);
	map = free_map(map);
	return (1);
}
