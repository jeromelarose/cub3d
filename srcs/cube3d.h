/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:18:05 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 16:58:21 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "get_next_line.h"
# include <stdlib.h>
# include "mlx.h"
# include <unistd.h>
# include <math.h>

typedef	struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				color;
	int				w;
	int				h;
	char			*tex;
}					t_img;

typedef struct		s_camera
{
	double			ratio;
	double			dirx;
	double			diry;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	int				stepx;
	int				stepy;
	int				side;
}					t_camera;

typedef struct		s_sprite
{
	double			mapx;
	double			mapy;
	t_img			pnj;
	double			dist;
	double			start;
	double			end;
	double			size;
	double			xtmp;
	double			stepy;
	double			stepx;
}					t_sprite;

typedef	struct		s_list
{
	t_sprite		sprite;
	struct s_list	*next;
	struct s_list	*back;
}					t_list;

typedef struct		s_map
{
	int				w;
	int				h;
	int				px;
	int				py;
	int				**grid;
	t_img			ground;
	t_img			sky;
	t_img			wall;
	t_img			*test;
	t_img			texno;
	t_img			texso;
	t_img			texwe;
	t_img			texea;
	double			*tab;
}					t_map;

typedef struct		s_perso
{
	t_img			tile;
	int				r;
	double			x;
	double			y;
	double			vx;
	double			vy;
	double			angle;
	double			speed;
	double			rotate_speed;
	char			sens;
	char			*texsprite;
}					t_perso;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	int				fd;
	int				save;
	char			*line;
	t_perso			perso;
	t_map			map;
	t_camera		camera;
	t_sprite		sprite;
	t_list			*list;
	double			agl;
}					t_window;

int					get_next_line(int fd, char **line);
char				**ft_split(const char *str, char charset);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(char *str);
void				init_grid(t_window *win);
char				*str_sup_set(char *str, char set);
void				print_map(t_window *win);
int					stop_perso(int key, t_window *win);
int					move_perso(int key, t_window *win);
int					move(t_window *win);
void				init_perso(t_window *win, int x, int y, char sens);
int					print_perso(t_window *win);
void				init_map(t_window *win);
t_img				init_img(t_window *win);
void				draw_square(t_img *img, int color);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
void				print_band(t_window *win, int x, double dist, int color);
void				lance_ray(t_window *win, int pix);
void				init_direction_ray(t_window *win, int pix);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
int					create_trgb(int t, int r, int g, int b);
int					get_b(int trgb);
int					get_g(int trgb);
int					get_r(int trgb);
int					get_t(int trgb);
void				parsing(t_window *win);
int					get_pixel(t_img *data, int x, int y);
int					init_tex(t_window *win, t_img *img);
void				ft_save(t_window *win);
void				print_sprite(t_window *win, t_sprite sprite);
void				print_sidex(t_window *win, int pix, double px);
void				print_sidey(t_window *win, int pix, double px);
void				gest_sprite(t_window *win);
t_list				*ft_lstnew(void);
void				ft_lstadd_back(t_list **lst, t_list *news);
void				ft_lstclear(t_list *lst);
void				gest_list(t_window *win);
t_list				*ft_lstlast(t_list *lst);
int					ft_islst(t_list *lst, int x, int y);
int					xclose(t_window *win);
void				error(t_window *win, char *str);
double				ret_dist(t_window *win, char c);
void				draw_fond(t_window *win);
int					is_num(char *s);
void				verif(t_window *win);
void				init_win(t_window *win);
void				free_tab(char **pars);
void				pars_perso(t_window *win, char **pars);

#endif
