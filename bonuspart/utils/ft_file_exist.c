/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:29:47 by stissera          #+#    #+#             */
/*   Updated: 2023/01/02 13:30:08 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd)
		return (close(fd));
	return (-1);
}
