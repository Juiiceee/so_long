/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:08 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/09 10:33:45 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/utils.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	freetab(char **area, int ligne)
{
	int	i;

	i = 0;
	while (i < ligne)
	{
		free(area[i]);
		i++;
	}
	free(area);
}

int	error(char *text)
{
	write (2, "Error\n", 6);
	write(2,text,ft_strlen(text));
	write (2, "\n", 1);
	return (0);
}

int	freereturn(char *str)
{
	free(str);
	return (-1);
}