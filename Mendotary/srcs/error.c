/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:12:54 by stissera          #+#    #+#             */
/*   Updated: 2023/01/02 19:30:25 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_error_next(int value)
{
	if (value == 0xB0)
		ft_putstr_fd("Error: Multiple player in card.\n", 1);
	else
		ft_putstr_fd("Exit\n", 1);
	return (0);
}

int	ft_error(int value)
{
	if (value == 1)
		ft_putstr_fd("Bad arguments!\n", 1);
	else if (value == 2)
		ft_putstr_fd("Initialisation error!\n", 1);
	else if (value == 4)
		ft_putstr_fd("Initialisation map error!\n", 1);
	else if (value == 8)
		ft_putstr_fd("Initialisation monsters error!\n", 1);
	else if (value == 0x10)
		ft_putstr_fd("Initialisation guns error!\n", 1);
	else if (value == 0x20)
		ft_putstr_fd("Initialisation ammo error!\n", 1);
	else if (value == 0x40)
		ft_putstr_fd("Initialisation items error!\n", 1);
	else if (value == 0x80)
		ft_putstr_fd("Initialisation screen error!\n", 1);
	else if (value == 0xFF)
		ft_putstr_fd("Malloc error!\n", 1);
	else if (value == 0xA0)
		ft_putstr_fd("Sprite file don't exist or bad access!\n", 1);
	else if (value == 0xAA)
		ft_putstr_fd("Bad argument color!\n", 1);
	else
		ft_error_next(value);
	return (0);
}
