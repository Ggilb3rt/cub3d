/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:41:23 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 12:53:14 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_errors(t_params *params)
{
	(void)params;
}

void	error_init(char *context)
{
	ft_putstr_fd("ERROR : Initialisation problème\n", 1);
	ft_putstr_fd(context, 1);
	ft_putstr_fd("\n***********\n", 1);
	exit(0);
}

void	ft_exit(char *context)
{
	ft_putstr_fd("ERROR : \n", 1);
	ft_putstr_fd(context, 1);
	exit(0);
}
