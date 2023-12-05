/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:22:22 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/05 14:30:19 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int	print_char(int args)
{
	ft_putchar(args);
	return (1);
}

int	print_nbr(int args)
{
	return (ft_putnbr(args));
}

int	print_str(char *args)
{
	return (ft_putstr(args));
}

int	print_hex(unsigned int args, char c)
{
	if (c == 'x')
		return (ft_putnbr_unsigned(args, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_unsigned(args, "0123456789ABCDEF"));
	else if (c == 'u')
		return (ft_putnbr_unsigned(args, "0123456789"));
	return (0);
}

int	print_ptr(void *args)
{
	if (!args)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2)
		+ ft_putnbr_size((size_t)args, "0123456789abcdef"));
}
