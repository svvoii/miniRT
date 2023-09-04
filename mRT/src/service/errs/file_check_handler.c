/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:51:23 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/04 19:04:59 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	instruction_switch(char **str, int **counters_ptr, int *correct)
{
	if (ft_strequals(str[0], "R"))
		check_resolution(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "A"))
		check_ambiance(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "c"))
		check_cameras(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "l"))
		check_lights(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "sp"))
		check_sphere(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "pl"))
		check_plane(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "sq") || ft_strequals(str[0], "cu"))
		check_square_cube(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "tr"))
		check_triangle(counters_ptr, correct, str);
	else if (ft_strequals(str[0], "co") || ft_strequals(str[0], "cy"))
		check_cone_cylinder(counters_ptr, correct, str);
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
	while (values[++i])
		free(values[i]);
	free(values);
}

void	check_row(int *correct, char *line, char ***values, int *entry)
{
	if (*correct)
	{
		*values = ft_whitespaces(line);
		if (*values && **values)
			instruction_switch(*values, &entry, correct);
		cleanup_arr(*values);
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

	correct = TRUE;
	i = -1;
	while (++i < INSTRUCTION_SET_SIZE)
		counters[i] = 0;
	/* this might be the second time to open file */
	fd = open(filename, O_RDONLY);
	//while (get_next_line(fd, &line))
	while (get_next_line(fd, line))
		check_row(&correct, line, &values, counters);
	check_row(&correct, line, &values, counters);
	close(fd);
	if (!correct || counters[RES] != 1 || counters[AMB] > 1 || counters[CAM] < 1)
	{
		return (false);
	}
	return (true);
}
