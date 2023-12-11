/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:04:16 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 17:28:35 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int	ft_putnbr_size(size_t n, char *base)
{
	char	*str;
	int		len;

	str = ft_itoa_size(n, base);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	longeurnombre_size(size_t n, int base)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		n /= base;
		length++;
	}
	return (length);
}

char	*ft_itoa_size(size_t n, char *base)
{
	int		length;
	char	*str;

	length = longeurnombre_size(n, ft_strlen(base));
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[length] = 0;
	while (n != 0)
	{
		str[--length] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (str);
}
