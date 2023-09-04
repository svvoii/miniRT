/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:03:51 by sbocanci          #+#    #+#             */
/*   Updated: 2023/09/04 18:54:45 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd, char *line)
{
	char	c_buffer;
	int		count;
	int		read_;

	if (fd < 0)
	{
		return (NULL);
	}
	count = 0;
	while ((read_ = read(fd, &c_buffer, 1)) > 0)
	{
		line[count] = c_buffer;
		count++;
		if (c_buffer == '\n')
		{
			break ;
		}
	}
	line[count] = '\0';
	if (read_ < 0 || (read_ == 0 && count == 0))
		return (NULL);
	return (line);
}

/*
//#define IN_FILE "in_file.txt"

int	main()
{
	char	line[LINE_BUF_SIZE];
	char	*l;
	int		fd;

	fd = 0;
	fd = open(IN_FILE, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening IN_FILE\n");
	}
	else
	{
		while ((l = get_next_line(fd, line)) != NULL)
		{
			printf("line: %s", line);
		}
	}
	printf("Exit. l: [%s]\n", l);
	close(fd);
	return (0);
}
*/