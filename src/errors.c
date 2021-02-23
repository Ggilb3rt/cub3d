/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:41:23 by ggilbert          #+#    #+#             */
/*   Updated: 2021/02/23 10:18:47 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_init(char *context)
{
	ft_putstr_fd("ERROR : Initialisation problème\n", 1);
	ft_putstr_fd(context, 1);
	ft_putstr_fd("\n***********\n", 1);
}