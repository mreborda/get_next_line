/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreborda <mreborda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:41:31 by mreborda          #+#    #+#             */
/*   Updated: 2022/12/15 14:05:12 by mreborda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	aux_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*line_join(char *line, char *buffer)
{
	int		i;
	int		d;
	char	*join;

	i = 0;
	d = 0;
	join = (char *)malloc(aux_strlen(line) + aux_strlen(buffer) + 1);
	if (!join)
		return (NULL);
	while (line && line[i])
	{
		join[i] = line[i];
		i++;
	}
	while (buffer[d])
	{
		join[i++] = buffer[d];
		if (buffer[d++] == '\n')
			break ;
	}
	join[i] = '\0';
	free(line);
	return (join);
}

int	buffer_clear(char *buffer)
{
	int	i;
	int	flag;
	int	d;

	flag = 0;
	d = 0;
	i = 0;
	while (buffer[i])
	{
		if (flag == 1)
		{
			buffer[d] = buffer[i];
			d++;
		}
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i] = 0;
		i++;
	}
	return (flag);
}
