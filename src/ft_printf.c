/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:17:33 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 17:28:35 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

int	check(char c, va_list args)
{
	int	nb;

	nb = 0;
	if (c == 'c')
		nb = print_char(va_arg(args, int));
	else if (c == 's')
		nb = print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		nb = print_nbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		nb = print_hex(va_arg(args, unsigned int), c);
	else if (c == 'u')
		nb = print_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		nb = print_ptr(va_arg(args, void *));
	else if (c == '%')
		nb = ft_putchar('%');
	return (nb);
}

int	ft_printall(int num_args, const char *str, va_list args)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (i < num_args)
	{
		if (str[i] == '%')
		{
			nb += check(str[i + 1], args);
			i += 2;
		}
		else
		{
			nb += ft_putchar(str[i]);
			i++;
		}
	}
	return (nb);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nb;

	if (!str)
		return (-1);
	va_start(args, str);
	nb = ft_printall(ft_strlen(str), str, args);
	va_end(args);
	return (nb);
}
