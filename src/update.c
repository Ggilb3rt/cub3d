/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:36:41 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/10 11:36:43 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_player(t_base *base)
{
	if (base->player->going_up == 1)
		move_up(base);
	if (base->player->going_down == 1)
		move_down(base);
	if (base->player->going_right == 1)
		move_chased_step(base, 'r');
	if (base->player->going_left == 1)
		move_chased_step(base, 'l');
	if (base->player->rotate_left == 1)
		look_left(base);
	if (base->player->rotate_right == 1)
		look_right(base);
}

void	update(t_base *base)
{
	move_player(base);
	base->player->is_moving = 0;
	if (base->can_move == TRUE)
		put_img(base);
	base->can_move = TRUE;
}
