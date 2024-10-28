/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:05:25 by azainabi          #+#    #+#             */
/*   Updated: 2024/10/19 01:44:56 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	handle_w_s(t_game *game)
{
	if (game->move_w)
	{
		if (ft_strchr("0O", \
		game->map[(int) \
		{game->player_posx + game->cast.dirx * game->move_speed}] \
		[(int){game->player_posy}]) != NULL)
			game->player_posx += game->cast.dirx * game->move_speed;
		if (ft_strchr("0O", game->map[(int)(game->player_posx)] \
		[(int)(game->player_posy + game->cast.diry * game->move_speed)]) \
		!= NULL)
			game->player_posy += game->cast.diry * game->move_speed;
	}
	if (game->move_s)
	{
		if (ft_strchr("0O", game->map[(int) \
		{game->player_posx - game->cast.dirx * game->move_speed}] \
		[(int){game->player_posy}]) != NULL)
			game->player_posx -= game->cast.dirx * game->move_speed;
		if (ft_strchr("0O", game->map[(int)(game->player_posx)] \
		[(int)(game->player_posy - game->cast.diry * game->move_speed)]) \
		!= NULL)
			game->player_posy -= game->cast.diry * game->move_speed;
	}
}

static void	handle_a_d(t_game *game)
{
	if (game->move_a)
	{
		if (ft_strchr("0O", game->map[(int) \
		{game->player_posx - game->cast.planex * game->move_speed}] \
		[(int){game->player_posy}]) != NULL)
			game->player_posx -= game->cast.planex * game->move_speed;
		if (ft_strchr("0O", \
		game->map[(int)(game->player_posx)] \
		[(int)(game->player_posy - game->cast.planey * game->move_speed)]) \
		!= NULL)
			game->player_posy -= game->cast.planey * game->move_speed;
	}
	if (game->move_d)
	{
		if (ft_strchr("0O", \
		game->map[(int) \
		{game->player_posx + game->cast.planex * game->move_speed}] \
		[(int){game->player_posy}]) != NULL)
			game->player_posx += game->cast.planex * game->move_speed;
		if (ft_strchr("0O", \
		game->map[(int)(game->player_posx)] \
		[(int)(game->player_posy + game->cast.planey * game->move_speed)]) \
		!= NULL)
			game->player_posy += game->cast.planey * game->move_speed;
	}
}

void	move(t_game *game)
{
	handle_w_s(game);
	handle_a_d(game);
	if (game->move_right)
	{
		rotate_right(game);
	}
	if (game->move_left)
	{
		rotate_left(game);
	}
}
