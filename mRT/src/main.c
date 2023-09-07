/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/07 09:03:21 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/*
void	check_counters(int *counters)
{
	if (!counters)
	{
		perror("invalid file\n");
		exit(EXIT_FAILURE);
	}
}
*/
void	check_file_creation(int *fd_list)
{
	if (!fd_list)
	{
		perror("unable to create output files\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	int			fd;
	//int			*fd_list;
	int			counters[INSTRUCTION_SET_SIZE];
	t_scene		s;
	t_allshapes	all_shapes;

	fd = check_arguments(ac, av);
	//fd_list = NULL;
	check_fd_argnum(fd, ac);
	if (check_file(av[ac - 1], counters) == false)
	{
		perror("invalid file\n");
		exit(EXIT_FAILURE);
	}
	/* ..CONTINUE TO MIGRATE LOGIC FROM HERE ..
	if (ac == 3)
	{
		fd_list = create_files(counters);
		check_file_creation(fd_list);
	}
	*/
	init_empty_shapes(&all_shapes);
	initialize_scene(&s);
	parse_scene(fd, &s, &all_shapes);
	/*
	if (ac == 3)
		save_scene(&s, fd_list);
	else
		display_scene(&s);
	*/
	return (0);
}
