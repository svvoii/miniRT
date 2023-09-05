/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 14:27:53 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../../../includes/minirt.h"

/* init_scene.c */
void	initialize_scene(t_scene *scene);

/* handle_scene.c */
void	init_empty_shapes(t_allshapes *all_shapes);
void	parse_scene(int fd, t_scene *s, t_allshapes *all_shapes);


/*
# define COLOR_CF 0.003921569 //WHY?
# define SHAPES			1
# define ALL			2
# define MAX_CAM		4
# define MAX_LIGHT		8
# define MAX_SHAPES		70

# define MAX_SPHERE		10
# define MAX_PLANE		10
# define MAX_SQUARE		10
# define MAX_CYLINDER	10
# define MAX_TRIANGLE	10
# define MAX_CONE		10
# define MAX_CUBE		10

** Setting up fixed max ammount for each shape
** presumably it will allow to run the traycer faster.
** 
** To check the t_plane..
** it seem to be an empty struct
typedef struct s_all_shapes
{
	t_sphere	sphere[MAX_SPHERE];
	t_plane		plane[MAX_PLANE];
	t_square	square[MAX_SQUARE];
	t_cylinder	cylinder[MAX_CYLINDER];
	t_triangle	triangle[MAX_TRIANGLE];
	t_cone		cone[MAX_CONE];
	t_cube		cube[MAX_CUBE];
}	t_all_shapes;

typedef struct scene
{
	int			resolution_x;
	int			resolution_y;
	double		ambi_ratio;
	t_tuple		ambi_color;
	int			camera_counter;
	t_camera	cameras[MAX_CAM];
	int			light_counter;
	t_light		lights[MAX_LIGHT];
	int			shape_counter;
	t_shape		shapes[MAX_SHAPES];
}	t_scene;
*/
/*
typedef struct scene
{
	int			resolution_x;
	int			resolution_y;
	double		ambi_ratio;
	t_tuple		*ambi_color;
	int			camera_counter;
	t_camera	**cameras;
	int			light_counter;
	t_light		**lights;
	int			shape_counter;
	t_shape		**shapes;
}	t_scene;
//void		init_scene(int *counters, t_scene *scene);
void		init_empty_shapes(t_all_shapes *all_shapes);
void		initialize_scene(t_scene *scene);
t_tuple		*get_tuple(char *value, char type);
void		free_scene(t_scene *s);
void		handle_r(char **input, t_scene *s);
void		handle_a(char **input, t_scene *s);
void		handle_c(char **input, t_scene *s);
void		handle_l(char **input, t_scene *s);
//void		handle_line(char **input, t_scene *s);
void		handle_line(char **input, t_scene *s, t_all_shapes *all_shapes);
void		handle_plane(char **values, t_scene *s);
//void		handle_sphere(char **values, t_scene *s);
void		handle_sphere(char **values, t_scene *s, t_all_shapes *all_shapes);
void		handle_square(char **values, t_scene *s);
void		handle_cylinder(char **values, t_scene *s);
void		handle_triangle(char **values, t_scene *s);
void		handle_cone(char **values, t_scene *s);
void		handle_cube(char **values, t_scene *s);
void		save_scene(t_scene *s, int *fd_list);
//void		parse_scene(int fd, int *counters, t_scene *s);
void		parse_scene(int fd, int *counters, t_scene *s, t_all_shapes *all_shapes);
void		cleanup(char **values);
int			*create_files(int *counters);

*/

#endif