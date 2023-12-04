/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:42:29 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/04 11:13:01 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*retour;
	size_t	i;

	i = nmemb * size;
	if (nmemb && i / nmemb != size)
		return (NULL);
	retour = malloc(nmemb * size);
	if (!retour)
		return (NULL);
	ft_bzero(retour, nmemb * size);
	return (retour);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chaine;
	size_t	len;
	int		i;
	int		t;

	len = ft_strlen(s1) + ft_strlen(s2);
	chaine = malloc(len + 1);
	i = 0;
	t = 0;
	if (!chaine)
		return (NULL);
	while (s1[i])
	{
		chaine[i] = s1[i];
		i++;
	}
	while (s2[t])
	{
		chaine[i + t] = s2[t];
		t++;
	}
	chaine[i + t] = '\0';
	return (chaine);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}
