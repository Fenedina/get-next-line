/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:45:08 by fenedina          #+#    #+#             */
/*   Updated: 2021/12/08 19:45:11 by fenedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_output(char *str_left)
{
	int		i;
	char	*str;

	i = 0;
	while (str_left[i] && str_left[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (str_left[i] && str_left[i] != '\n')
	{
		str[i] = str_left[i];
		i++;
	}
	if (str_left[i] && str_left[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *str_left)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!str_left[i])
	{
		free(str_left);
		return (NULL);
	}
	while (str_left[i] && str_left[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (str_left[i])
		str[j++] = str_left[i++];
	str[j] = '\0';
	free(str_left);
	return (str);
}

char	*ft_read(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		i;

	i = 1;
	if (ft_strchr(str, '\n'))
		return (str);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		if (i == 0 && *str)
			return (str);
		buf[i] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		free(temp);
	}
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line_output;
	static char	*str;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT32_MAX)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line_output = ft_output(str);
	if (ft_strchr(line_output, '\n'))
		str = ft_save(str);
	else
	{
		free(str);
		str = NULL;
	}
	return (line_output);
}
