/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_exceptions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 13:17:00 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	check_arguments(int ac, char **av)
{
	int	fd;

	fd = 0;
	if (ac == 3 || ac == 2)
		fd = open(av[ac - 1], O_RDONLY);
	if (ac < 2 || ac > 3
		|| (ac == 3 && !((ft_strequals(av[1], "--save"))))
		|| !fd)
	{
		perror("wrong argument");
		return (-1);
	}
	if (fd == -1)
	{
		perror("file not found");
		return (-1);
	}
	return (fd);
}

void	check_fd_argnum(int fd, int ac)
{
	if (fd < 1 || ac < 2 || ac > 3)
		exit(EXIT_FAILURE);
}
