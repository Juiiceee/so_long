/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:23 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/12 14:21:37 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include <stdlib.h>

//map_utils.c
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		error(char *text);
int		freereturn(char *str);

#endif
