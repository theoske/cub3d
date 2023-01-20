/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:12:54 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 17:34:39 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	ft_error_next(int value)
{
	if (value == 0xB0)
		ft_putstr_fd("Error reserve 4.\n", 1);
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
		ft_putstr_fd("Initialisation screen error!\n", 1);
	else if (value == 0x10)
		ft_putstr_fd("Malloc error!\n", 1);
	else if (value == 0x20)
		ft_putstr_fd("Map file error!\n", 1);
	else if (value == 0x40)
		ft_putstr_fd("Bad argument color!\n", 1);
	else if (value == 0x80)
		ft_putstr_fd("Bad or not placement of player!\n", 1);
	else if (value == 0xFF)
		ft_putstr_fd("Unknow caractere in map!\n", 1);
	else if (value == 0xA0)
		ft_putstr_fd("Error: Texture missing!\n", 1);
	else if (value == 0xAA)
		ft_putstr_fd("Error reserve 3!\n", 1);
	else
		ft_error_next(value);
	return (0);
}
