/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:01:55 by azainabi          #+#    #+#             */
/*   Updated: 2024/10/19 21:28:05 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d_bonus.h"

static void	set_index(t_game *game, t_cast *cast)
{
	if (cast->side == 1 && cast->raydiry > 0)
		game->index = 0;
	if (cast->side == 1 && cast->raydiry < 0)
		game->index = 2;
	if (cast->side == 0 && cast->raydirx > 0)
		game->index = 3;
	if (cast->side == 0 && cast->raydirx < 0)
		game->index = 4;
	if (game->map[cast->mapx][cast->mapy] == 'D')
		game->index = 1;
}

void	init_texture(t_game *game, t_cast *cast)
{
	set_index(game, cast);
	if (cast->side == 0)
		cast->wallx = game->player_posy + cast->walldist * cast->raydiry;
	else
		cast->wallx = game->player_posx + cast->walldist * cast->raydirx;
	cast->wallx -= floor(cast->wallx);
	cast->tex_x = (int)(cast->wallx * \
	(double)(game->mlx_t.texture_wall[game->index].width));
	if (cast->side == 0 && cast->raydirx < 0)
		cast->tex_x = \
		game->mlx_t.texture_wall[game->index].width - cast->tex_x - 1;
	if (cast->side == 1 && cast->raydiry > 0)
		cast->tex_x = \
		game->mlx_t.texture_wall[game->index].width - cast->tex_x - 1;
	cast->step = (1.0 * game->mlx_t.texture_wall[game->index].height) / \
	cast->lineheight;
	cast->texpos = (game->start_draw - game->height / 2 + cast->lineheight / 2) \
	* cast->step;
}
