/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:56:30 by azainabi          #+#    #+#             */
/*   Updated: 2024/10/24 10:44:25 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_close(void *ptr)
{
	t_game *game = (t_game *)ptr;
	// mlx_destroy_window(game->mlx_t.mlx_ptr, game->mlx_t.mlx_window);
	mlx_close_window(game->mlx_t.mlx);
	my_malloc(0, 0);
	// return (0);
}
void	key_press(void *ptr)
{
	t_game *game = (t_game *)ptr;
	if (mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_ESCAPE))
		ft_close(game);
	if (mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_W))
		game->move_w = 1;
	if (mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_S))
		game->move_s = 1;
	if (mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_A))
		game->move_a = 1;
	if (mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_D))
		game->move_d = 1;
	if (mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_RIGHT))
		game->move_right = 1;
	if (mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_LEFT))
		game->move_left = 1;
	// return (0);
}
void	key_release(void *ptr)
{
	t_game *game = (t_game *)ptr;
	if (!mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_W))
		game->move_w = 0;
	if (!mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_S))
		game->move_s = 0;
	if (!mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_A))
		game->move_a = 0;
	if (!mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_D))
		game->move_d = 0;
	if (!mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_RIGHT))
		game->move_right = 0;
	if (!mlx_is_key_down(game->mlx_t.mlx, MLX_KEY_LEFT))
		game->move_left = 0;
	// return (0);
}

void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx_t.mlx, key_press, game);
	mlx_loop_hook(game->mlx_t.mlx, key_release, game);
	// mlx_loop_hook(game->mlx_t.mlx, ft_close, game);
}
