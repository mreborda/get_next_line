/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreborda <mreborda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:40:19 by mreborda          #+#    #+#             */
/*   Updated: 2022/12/15 15:07:54 by mreborda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = line_join(line, buffer);
		if (buffer_clear(buffer))
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*temp;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	printf("output %s\n", get_next_line(fd));
// 	printf("output %s\n", get_next_line(fd));
// 	do {
// 			temp = get_next_line(fd);
// 			free(temp);
// 		} while (temp != NULL);
// 	printf("output %s\n", get_next_line(fd));
// 	return (fd);
// }
