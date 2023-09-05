/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:51:23 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 18:22:01 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/* DEBUG */
void	print_counters(int *counters)
{
	int i = 0;
	
	while (i < INSTRUCTION_SET_SIZE)
	{
		printf("counter[%d]: [%d]\n", i, counters[i]);
		i++;
	}
}

void	print_strings(char **strings)
{
	int	i = 0;

	while (strings[i])
	{
		printf("\t[%d]: [%s]\n", i, strings[i]);
		i++;
	}
}
/* ***** */
void	instruction_switch(char **str, int *counters, int *correct)
{
	if (ft_strequals(str[0], "R"))
		check_resolution(counters, correct, str);
	else if (ft_strequals(str[0], "A"))
		check_ambiance(counters, correct, str);
	else if (ft_strequals(str[0], "c"))
		check_cameras(counters, correct, str);
	else if (ft_strequals(str[0], "l"))
		check_lights(counters, correct, str);
	else if (ft_strequals(str[0], "sp"))
		check_sphere(counters, correct, str);
	else if (ft_strequals(str[0], "pl"))
		check_plane(counters, correct, str);
	else if (ft_strequals(str[0], "sq") || ft_strequals(str[0], "cu"))
		check_square_cube(counters, correct, str);
	else if (ft_strequals(str[0], "tr"))
		check_triangle(counters, correct, str);
	else if (ft_strequals(str[0], "co") || ft_strequals(str[0], "cy"))
		check_cone_cylinder(counters, correct, str);
	else
		*correct = 0;
}

/*
int	*make_counters_array(void)
{
	int	*counters;
	int	i;

	i = -1;
	counters = malloc(sizeof(int) * INSTRUCTION_SET_SIZE);
	while (++i < INSTRUCTION_SET_SIZE)
		counters[i] = 0;
	return (counters);
}
*/

void	cleanup_arr(char **values)
{
	int	i;

	i = -1;
	while (values && values[++i])
		free(values[i]);
	free(values);
}

void	check_row(int *correct, char *line, char **values, int *counters)
{
	if (*correct)
	{
		values = ft_whitespaces(line);
		if (values && *values)
			instruction_switch(values, counters, correct);
		cleanup_arr(values);
	}
	//free(*line);
}

bool	check_file(char *filename, int *counters)
{
	int		fd;
	char	line[GNL_BUF_SIZE];
	char	**values;
	int		correct;
	int		i;

	values = NULL;
	correct = TRUE;
	i = -1;
	while (++i < INSTRUCTION_SET_SIZE)
		counters[i] = 0;
	/* this might be the second time to open file */
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, line))
		check_row(&correct, line, values, counters);
	check_row(&correct, line, values, counters);
	close(fd);

	/* DEBUG */
	//print_counters(counters);
	/* ***** */
	if (!correct || counters[RES] != 1 || counters[AMB] > 1 || counters[CAM] < 1)
	{
		return (false);
	}
	return (true);
}
