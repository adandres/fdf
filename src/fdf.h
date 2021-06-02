/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                           /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:29:46 by adandres          #+#    #+#             */
/*   Updated: 2020/06/25 20:11:37 by adandres                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define E map->ligne.dx
# include "/usr/X11/include/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# define W 600
# define H 400
# define P_I (M_PI / 180)
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_ligne
{
	int			x;
	int			y;
	int			col;
	int			x1;
	int			y1;
	int			col1;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
	int			buffer;
}				t_ligne;

typedef struct	s_square
{
	int			xo;
	int			yo;
	int			xf;
	int			yf;
}				t_square;

typedef struct	s_mat
{
	double		cosx;
	double		cosy;
	double		cosz;
	double		sinx;
	double		siny;
	double		sinz;
	int			tx;
	int			ty;
	int			tz;
}				t_mat;

typedef struct	s_col
{
	int			prev_x;
	int			col;
	int			tmax;
	int			tmin;
	int			col_min;
	int			col_max;
}				t_col;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	float		i;
	float		j;
	int			**map;
	int			oc;
	int			tz_mov;
	int			var;
	int			d;
	int			w;
	int			x;
	int			y;
	int			l_b;
	int			i_b;
	int			l_col;
	int			i_col;
	int			color;
	int			width;
	int			height;
	t_mat		mat;
	t_img		img;
	t_col		col;
	t_ligne		ligne;
}				t_map;

void			sup_l(int x, int y, int xf, t_map *map);
int				calc_dx(int x, int y, int z, t_map **maps);
int				calc_dy(int x, int y, int z, t_map **maps);
int				calc_dz(int x, int y, int z, t_map **maps);
int				help_for_atoi_tab(t_map **maps);
void			deal_fdf(t_map **maps);
int				init(t_map **maps);
int				is_in_screen(t_map *map);
int				deal_key(int key, t_map **maps);
int				deal_mouse(int button, int x, int y, t_map **maps);
void			print_square(int yo, int yf, t_map **maps);
t_map			*read_input(int fd);
void			mlx_hook_it(t_map **maps);
int				make_image(t_map **maps, int o);
void			print_color_square(t_square q, t_map **maps);
void			color_map_dy(int i, t_map **maps);
void			color_map_dx(int i, t_map **maps);
void			print_ligne1(t_map **maps);
void			print_ligne2(t_map **maps);
void			fill_ligne(int x, int y, int col, t_map **maps);
void			init_var(t_map **maps);
void			calc_sin_cos(t_map **maps);
void			assign_key(int k, t_map **maps);
char			**free_char_tab(char ***tab);
t_map			*free_map(t_map *map);
t_square		assign_squar(int a, int b, int c, int d);
int				init_display(t_map *map);
void			print_it(t_square q, t_map *map);
int				col_with_var(double t, t_map *p);
int				col_out_var(double t, t_map *p);
void			init_zoom(t_map **maps);
void			init_matrice(t_map **maps);
void			init_disp(t_map **maps);
void			print_string(int x, int y, char *str, t_map *map);

#endif
