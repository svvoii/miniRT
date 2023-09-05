/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:41:24 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 15:37:56 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	init_matrix(t_matrix *m)
{
	int	y;
	int	x;

	y = 0;
	while (y < M_MAX)
	{
		x = 0;
		while (x < M_MAX)
		{
			m->matrix[y][x] = 0;
			x++;
		}
		y++;
	}
	m->h = 0;
	m->w = 0;
}

void	init_cameras(t_camera *cam)
{
	cam->active = false;
	set_tuple(&cam->from, "0,0,0", POINT);
	cam->h_size = 0;
	cam->v_size = 0;
	cam->pix_size = 0.0;
	init_matrix(&cam->transform);
	cam->half = 0.0;	
	cam->half_w = 0.0;
	cam->half_h = 0.0;
	cam->aspect = 0.0;
}

void	init_lights(t_light *lights)
{
	set_tuple(&lights->position, "0,0,0", POINT);
	set_tuple(&lights->color, "0,0,0", COLOR);
}

void	init_matrl(t_matrl *matrl)
{
	set_tuple(&matrl->color, "0,0,0", COLOR);
	matrl->diffuse = 0.0;	
	matrl->ambient = 0.0;	
	matrl->specular = 0.0;	
	matrl->shininess = 0.0;	
}

/*
** Setting all t_shape structs to 0 and NULL
*/
void	init_shapes(t_shape *shapes)
{
	shapes->type = NONE;
	init_matrl(&shapes->matrl);		
	init_matrix(&shapes->trans);
	shapes->shape = NULL;
}

/*
** Here we initialize the main t_scene structure with empty values
*/
void	initialize_scene(t_scene *scene)
{
	int	i;

	scene->resolution_x = -1;
	scene->resolution_y = -1;
	scene->ambi_ratio = -1;
	set_tuple(&scene->ambi_color, "0,0,0", COLOR);
	scene->camera_counter = 0;
	scene->light_counter = 0;
	scene->shape_counter = 0;
	i = -1;
	while (++i < MAX_CAM)
		init_cameras(&scene->cameras[i]);
	i = -1;
	while (++i < MAX_LIGHT)
		init_lights(&scene->lights[i]);
	i = -1;
	while (++i < MAX_SHAPES)
		init_shapes(&scene->shapes[i]);
	/* DEBUG 
	//scene->cameras = (t_camera **)malloc(sizeof(t_camera *) * counters[CAM]);
	scene->lights = (t_light **)malloc(sizeof(t_light *) * counters[LHT]);
	scene->shapes = (t_shape **)malloc(
			sizeof(t_shape *) * count_what(counters, SHAPES));
	*/
}

/*
** INITIALIZUING ALL SHAPES AS EMPTY
*/
void	init_sphere(t_sphere *sphere);
/*
void	init_plane(t_plane *plane);
void	init_square(t_square *square);
void	init_cylinder(t_cylinder *cylinder);
void	init_triangle(t_triangle *triangle);
void	init_cone(t_cone *cone);
void	init_cube(t_cube *cube);
*/

void	init_sphere(t_sphere *sphere)
{
	sphere->active = false;
	set_tuple(&sphere->centre, "0,0,0", POINT);
}

/*
void	init_plane(t_plane *plane)
{
	plane->active = false;
	set_tuple(&plane->point, "0,0,0", POINT);
}

void	init_square(t_square *square)
{
	square->active = false;
	init_triangle(&square->t1);
	init_triangle(&square->t2);
	set_tuple(&square->center, "0,0,0", POINT);
	set_tuple(&square->norm, "0,0,0", POINT); // check if it is POINT or VECTOR
	set_tuple(&square->color, "0,0,0", COLOR);
	init_matrix(&square->trans);
	square->side = 0.0;
}

void	init_cylinder(t_cylinder *cylinder)
{
	cylinder->active = false;
	cylinder->min = 0.0;
	cylinder->max = 0.0;
	cylinder->closed = 0;
	set_tuple(&cylinder->center, "0,0,0", POINT);
	set_tuple(&cylinder->norm, "0,0,0", POINT); // check if it is POINT or VECTOR
	set_tuple(&cylinder->color, "0,0,0", COLOR);
	init_matrix(&cylinder->trans);
	cylinder->d = 0.0;
	cylinder->a = 0.0;
	cylinder->b = 0.0;
	cylinder->c = 0.0;
	cylinder->disc = 0.0;
}

void	init_triangle(t_triangle *triangle)
{
	triangle->active = false;
	set_tuple(&triangle->a, "0,0,0", POINT);
	set_tuple(&triangle->b, "0,0,0", POINT);
	set_tuple(&triangle->c, "0,0,0", POINT);
	set_tuple(&triangle->e1, "0,0,0", POINT);
	set_tuple(&triangle->e2, "0,0,0", POINT);
	set_tuple(&triangle->n, "0,0,0", POINT);
	set_tuple(&triangle->dir_cros, "0,0,0", POINT);
	set_tuple(&triangle->or_crs, "0,0,0", POINT);
	set_tuple(&triangle->a_to_org, "0,0,0", POINT);
	triangle->det = 0.0;
	triangle->f = 0.0;
	triangle->u = 0.0;
	triangle->v = 0.0;
	triangle->t = 0.0;
}

void	init_cone(t_cone *cone)
{
	cone->active - false;
	cone->min = 0.0;
	cone->max = 0.0;
	cone->closed = 0;
	set_tuple(&cone->center, "0,0,0", POINT);
	set_tuple(&cone->norm, "0,0,0", POINT); // check if it is POINT or VECTOR
	set_tuple(&cone->color, "0,0,0", COLOR);
	init_matrix(&cone->trans);
	cone->d = 0.0;
	cone->a = 0.0;
	cone->b = 0.0;
	cone->c = 0.0;
	cone->disc = 0.0;
}

void	init_cube(t_cube *cube)
{
	cube->active = false;
	set_tuple(&cube->center, "0,0,0", POINT);
	cube->side = 0.0;
	set_tuple(&cube->color, "0,0,0", COLOR);
	set_tuple(&cube->norm, "0,0,0", POINT); // check if it is POINT or VECTOR
	init_matrix(&cube->trans);
}
*/

void	init_empty_shapes(t_allshapes *allshapes)
{
	int	i;

	i = -1;
	while (++i < MAX_SPHERE)
		init_sphere(&allshapes->sphere[i]);
	/*
	init_plane(&all_shapes->plane);
	init_square(&all_shapes->square);
	init_cylinder(&all_shapes->cylinder);
	init_triangle(&all_shapes->triangle);
	init_cone(&all_shapes->cone);
	init_cube(&all_shapes->cube);
	*/
}