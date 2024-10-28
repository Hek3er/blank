/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:56:00 by azainabi          #+#    #+#             */
/*   Updated: 2024/10/25 17:56:34 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_gun(t_game *game, char *path)
{
	// game->mlx_t.texture.mlx_img = mlx_xpm_file_to_image(game->mlx_t.mlx_ptr, \
	// path, &game->mlx_t.texture.width, &game->mlx_t.texture.height);
	// if (game->mlx_t.texture_tex)
	// 	mlx_delete_xpm42(game->mlx_t.texture_tex);
	game->mlx_t.texture_tex = mlx_load_xpm42(path);
	if (!game->mlx_t.texture_tex)
	{
		mlx_close_window(game->mlx_t.mlx);
		ft_exit("mxl failed to init image3\n", 1);
	}
	// if (game->mlx_t.texture)
		mlx_delete_image(game->mlx_t.mlx, game->mlx_t.texture);
	game->mlx_t.texture = mlx_texture_to_image(game->mlx_t.mlx, &game->mlx_t.texture_tex->texture);
	// game->mlx_t.texture.img_data = \
	// mlx_get_data_addr(game->mlx_t.texture.mlx_img, &game->mlx_t.texture.bpp, \
	// &game->mlx_t.texture.len, &game->mlx_t.texture.endian);
	// if (!game->mlx_t.texture.img_data)
	// {
	// 	mlx_destroy_window(game->mlx_t.mlx_ptr, game->mlx_t.mlx_window);
	// 	ft_exit("mxl failed to init image\n", 1);
	// }
	// mlx_put_image_to_window(game->mlx_t.mlx_ptr, game->mlx_t.mlx_window, \
	// game->mlx_t.texture.mlx_img, game->width / 2 - game->mlx_t.texture.width \
	// / 2, game->height - game->mlx_t.texture.height);
	if (mlx_image_to_window(game->mlx_t.mlx, game->mlx_t.texture, game->width / 2 - game->mlx_t.texture->width / 2, game->height - game->mlx_t.texture->height) == -1)
	{
		mlx_close_window(game->mlx_t.mlx);
		ft_exit("mxl failed to init image1\n", 1);
	}
}

void	draw_wall_t(t_game *game, char *path, int i)
{
	// game->mlx_t.texture_wall[i].mlx_img = mlx_xpm_file_to_image \
	// (game->mlx_t.mlx_ptr, path, &game->mlx_t.texture_wall[i].width, \
	// &game->mlx_t.texture_wall[i].height);
	game->mlx_t.texture_wall_tex[i] = mlx_load_xpm42(path);
	if (!game->mlx_t.texture_wall_tex[i])
	{
		mlx_close_window(game->mlx_t.mlx);
		ft_exit("mxl failed to init image\n", 1);
	}
	// game->mlx_t.texture_wall[i].img_data = mlx_get_data_addr \
	// (game->mlx_t.texture_wall[i].mlx_img, &game->mlx_t.texture_wall[i].bpp, \
	// &game->mlx_t.texture_wall[i].len, &game->mlx_t.texture_wall[i].endian);
	// if (!game->mlx_t.texture_wall[i].img_data)
	// {
	// 	mlx_destroy_window(game->mlx_t.mlx_ptr, game->mlx_t.mlx_window);
	// 	ft_exit("mxl failed to init image\n", 1);
	// }
}

static void	init_mlx(t_game *game)
{
	game->mlx_t.mlx = mlx_init(game->width, game->height, "cub3d", false);
	if (!game->mlx_t.mlx)
		ft_exit("mlx failed to init\n", 1);
	game->mlx_t.img = mlx_new_image(game->mlx_t.mlx, game->width, game->height);
	if (!game->mlx_t.img)
	{
		mlx_close_window(game->mlx_t.mlx);
		ft_exit("mxl failed to init image2\n", 1);
	}
}

void	init_param(t_game *game, t_cast *cast)
{
	game->width = 1920;
	game->height = 1280;
	game->move_w = 0;
	game->move_s = 0;
	game->move_a = 0;
	game->move_d = 0;
	game->move_right = 0;
	game->move_left = 0;
	game->move_speed = 0.2;
	game->rotating_speed = 0.07;
	game->wall_height = 0.7;
	cast->hit = 0;
	game->doorx = 0;
	game->doory = 0;
	game->index = 0;
	game->old_mouse_x = 0;
	handle_directions(game);
	init_mlx(game);
}
