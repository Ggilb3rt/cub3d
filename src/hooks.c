/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:36:31 by ptroger           #+#    #+#             */
/*   Updated: 2022/02/11 15:54:00 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_win(t_base *base)
{
	(void)base;
	destroy_base(base, "finished");
	return (0);
}

int	key_press(int keycode, t_base *base)
{
	if (keycode == R_LEFT)
		base->player->rotate_left = 1;
	if (keycode == R_RIGHT)
		base->player->rotate_right = 1;
	if (keycode == ESC)
		close_win(base);
	if (keycode == W)
		base->player->going_up = 1;
	if (keycode == S)
		base->player->going_down = 1;
	if (keycode == Q)
		base->player->going_left = 1;
	if (keycode == D)
		base->player->going_right = 1;
	update(base);
	return (0);
}

int	key_release(int keycode, t_base *base)
{
	if (keycode == R_LEFT)
		base->player->rotate_left = 0;
	if (keycode == R_RIGHT)
		base->player->rotate_right = 0;
	if (keycode == W)
		base->player->going_up = 0;
	else if (keycode == S)
		base->player->going_down = 0;
	else if (keycode == Q)
		base->player->going_left = 0;
	else
		base->player->going_right = 0;
	return (0);
}
