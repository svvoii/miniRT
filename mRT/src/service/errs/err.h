/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 17:28:00 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# include "../../../includes/minirt.h"

/* input_exceptions.c */
int		check_arguments(int ac, char **av);
void	check_fd_argnum(int fd, int ac);

/* file_chaeck_handler.c */
bool	check_file(char *filename, int *counters);


/* file_instructions_checker.c */
void	check_resolution(int *counters, int *is_correct, char **str);
void	check_ambiance(int *counters, int *is_correct, char **str);
void	check_cameras(int *counters, int *is_correct, char **str);
void	check_lights(int *counters, int *is_correct, char **str);

/* file_shape_description.c */
void	check_sphere(int *counters, int *is_correct, char **str);
void	check_plane(int *counters, int *is_correct, char **str);
void	check_square_cube(int *counters, int *is_correct, char **str);
void	check_triangle(int *counters, int *is_correct, char **str);
void	check_cone_cylinder(int *counters, int *is_correct, char **str);

/* ERR DEBUG */
void	print_counters(int *counters);
void	print_strings(char **strings);

#endif