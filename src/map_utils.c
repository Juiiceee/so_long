/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:08 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/12 14:20:30 by lbehr            ###   ########.fr       */
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

int	error(char *text)
{
	ft_printf("Error\n%s\n", text);
	return (0);
}

int	freereturn(char *str)
{
	free(str);
	return (-1);
}
