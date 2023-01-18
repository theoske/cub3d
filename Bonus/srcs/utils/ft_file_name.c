/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:39:10 by stissera          #+#    #+#             */
/*   Updated: 2023/01/03 17:39:50 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_file_name(char *file)
{
	int	i;

	i = 0;
	while (file && file[i])
		i++;
	if (ft_strncmp(&file[i - 4], ".cub", 5))
		return (1);
	return (0);
}
