/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:29:47 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 17:42:34 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/includes/cub3d.h"

int	ft_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd)
		return (close(fd));
	return (-1);
}
