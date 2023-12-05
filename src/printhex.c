/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:07:39 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/05 14:30:22 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, char *base)
{
	char	*str;
	int		len;

	str = ft_itoa_unsigned(n, base);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	longeurnombre_unsigned(unsigned int n, int base)
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

char	*ft_itoa_unsigned(unsigned int n, char *base)
{
	int		length;
	char	*str;

	length = longeurnombre_unsigned(n, ft_strlen(base));
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
