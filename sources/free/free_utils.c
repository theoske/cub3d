/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:44:22 by stissera          #+#    #+#             */
/*   Updated: 2023/01/20 17:36:23 by tkempf-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_free_str(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (0);
}

int	ft_free_int(int *nbr)
{
	if (nbr)
		free(nbr);
	nbr = 0;
	return (0);
}

int	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab && tab[++i])
			free(tab[i]);
		free(tab);
		tab = NULL;
	}
	return (0);
}

int	ft_free_tab_int(int **tab)
{
	size_t	i;

	i = -1;
	if (tab)
	{
		while (tab && tab[++i])
			free(tab[i]);
		free(tab);
		tab = 0;
	}
	return (0);
}
