/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:52:49 by fenedina          #+#    #+#             */
/*   Updated: 2021/12/08 19:52:51 by fenedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*a;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (src[i] != '\0')
	{
		c++;
		i++;
	}
	a = malloc(sizeof(char) * c + 1);
	if (0 == a)
		return (0);
	i = 0;
	while (src[i])
	{
		a[i] = src[i];
		i++;
	}
	a[i] = 0;
	return (a);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*str_new;
	int		len;

	i = 0;
	str_new = 0;
	len = ft_strlen(str);
	if (ch > 256)
		ch = ch - 256;
	while (str[i] != ch && i <= len && str[i] != '\0')
	{
		i++;
	}
	if (len < 0)
		return (0);
	if (str[i] == ch)
		str_new = (char *)&str[i];
	return (str_new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (0 == a)
		return (NULL);
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		a[i++] = s2[j++];
	}
	a[i] = '\0';
	return (a);
}
