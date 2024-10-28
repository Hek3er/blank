/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:56:48 by azainabi          #+#    #+#             */
/*   Updated: 2024/10/24 08:59:11 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <limits.h>
# include "MLX42.h"
# include "get_next_line.h"

# define FOV 66

# define ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_SPACE 49
# define KEY_O 31

typedef struct vector2d
{
	int	x;
	int	y;
}				t_vector2d;

typedef struct s_data
{
	void			*data;
	struct s_data	*next;
}	t_data;

typedef struct s_image
{
	int		width;
	int		height;
	void	*mlx_img;
	char	*img_data;
	int		bpp;
	int		len;
	int		endian;
}				t_img;
typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*texture_wall[5];
	mlx_image_t		*texture;
	xpm_t			*texture_wall_tex[5];
	xpm_t			*texture_tex;
}				t_mlx;

typedef struct s_cast
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	double	camx;
	double	deltax;
	double	deltay;
	double	sidedistx;
	double	sidedisty;
	double	walldist;
	double	wallx;
	double	step;
	double	texpos;
	int		stepx;
	int		stepy;
	int		side;
	int		hit;
	int		mapx;
	int		mapy;
	int		tex_x;
	int		flag_center;
	double	distance_to_center;
	int		lineheight;
}				t_cast;

typedef struct s_textures
{
	char	*name;
	int		*field;
	char	*error_msg;
}	t_textures;

typedef struct s_game
{
	int			index;
	int			fd; // added by salah
	int			fd2; // added by salah
	int			no; // added by salah
	int			so; // added by salah
	int			we; // added by salah
	int			ea; // added by salah
	int			c; // added by salah
	int			f; // added by salah
	char		*ln; // added by salah
	char		*line; // added by salah
	int			start_i; // added by salah
	int			end_i; // added by salah
	int			start_j; // added by salah
	int			end_j; // added by salah
	int			x_player; // added by salah
	int			y_player; // added by salah
	double		scale_x; // added by salah
	double		scale_y; // added by salah
	double		width_minimap; // added by salah
	double		height_minimap; // added by salah
	double		player_minimap_x;
	double		player_minimap_y;
	int			width;
	int			height;
	char		**map;
	int			mapx; // how many rows in map
	int			mapy; // how many columns in map
	int			mapx1; // how many rows in map
	int			mapy1; // how many columns in map
	int			tile_s;
	int			number_of_players;
	double		player_posx; //player position in x relative to map (map[x][y])
	double		player_posy; //player position in y relative to map (map[x][y])
	double		move_speed;
	double		rotating_speed;
	double		wall_height;
	char		orientation;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			ciel_color;
	int			floor_color;
	int			start_draw;
	int			end_draw;
	int			x;
	int			move_w;
	int			move_s;
	int			move_a;
	int			move_d;
	int			move_right;
	int			move_left;
	int			doorx;
	int			doory;
	int			old_mouse_x;
	t_mlx		mlx_t;
	t_cast		cast;
}	t_game;

//parcing
int		path_of_txr_nm(char *line, char *texture_name);
void	ft_error_texture(void);
char	*pt_txr(t_game *m, char *line);
int		pt_ciel(char *line, char *texture_name);
char	*ft_strchr(const char *s, int c);
int		is_near_door(t_game *maps);
void	ft_init_map(t_game *maps);
int		ft_textures(t_game *maps, char *av);
int		ft_isdigit(int c);
char	*ft_strjoin_char(char const *s1, char s2);
int		ft_atoi(const char *str);
int		ft_ciel(char *char_color);
void	*my_malloc(size_t size, int mode);
void	ft_error_zero(void);
// void	ft_check_args(int ac, char **av);
void	ft_check_args(int ac, char **av);
int		ft_search(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
void	ft_strcpy(char *dest, char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// char	**ft_read_map(int fd, char *line, t_game *map);
int		ft_read_map(int fd, char *line, t_game *maps);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	ft_copy_map(char *av, t_game *maps);
void	player_check(char **map);
int		check_firstline(char *line);
void	ft_check_zeros(char **map);

//.Functions
void	draw_rectangle(int dimensionsx, int dimensionsy, \
int color, t_game *game);
void	draw_rectangle_for_player(int dimensionsx, \
int dimensionsy, int color, t_game *game);
int		convert_rgb_to_int(int r, int g, int b);
double	get_fov(double angle);
// int		ft_strlen(char *str);
// char	*ft_strdup(char *str);
void	ft_write(char *str, int fd);
void	ft_exit(char *str, int code);
void	draw_pixel(int x, int y, t_game *game, int color);
void	init_vector(t_vector2d *vec, int x, int y);
void	init_hooks(t_game *game);
void	draw_vert_line(t_game *game);
int		wall_hit(t_game *game, int x, int y);
void	init_param(t_game *game, t_cast *cast);
void	init_map(t_game *game); // parsing
void	casting(t_game *game, t_cast *cast);
void	draw_gun(t_game *game, char *path);
void	handle_directions(t_game *game);
void	update_game(t_game *game);
void	draw_wall_t(t_game *game, char *path, int i);
void	init_texture(t_game *game, t_cast *cast);
void	get_d_cord(t_game *maps);
void	set_wall_t(t_game *game);
void	move(t_game *game);
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);

#endif
