/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:50:23 by azainabi          #+#    #+#             */
/*   Updated: 2024/10/24 11:02:06 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	update_game(t_game *game)
{
	// mlx_clear_window(game->mlx_t.mlx_ptr, game->mlx_t.mlx_window);
	// mlx_delete_image(game->mlx_t.mlx, game->mlx_t.texture);
	mlx_delete_image(game->mlx_t.mlx, game->mlx_t.img);
	game->mlx_t.img = mlx_new_image(game->mlx_t.mlx, game->width, game->height);
	move(game);
	casting(game, &game->cast);
	// mlx_put_image_to_window(game->mlx_t.mlx_ptr, \
	// game->mlx_t.mlx_window, game->mlx_t.img.mlx_img, 0, 0);
	if (mlx_image_to_window(game->mlx_t.mlx, game->mlx_t.img, 0, 0) == -1) {
		printf("error putting image to window\n");
		mlx_close_window(game->mlx_t.mlx);
	}
	
	draw_gun(game, "./mandatory/textures/gun/0.xpm42");
}
