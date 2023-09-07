/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/01 15:48:20by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minirt.h"

void	activate_sphere(t_shape *shape, t_sphere *sphere)
{
	sphere->active = true;
	shape->type = SPHERE;
	shape->shape = sphere;
}

void	matrix_with_color(t_shape *shape, t_tuple *color)
{
	copy_tuple(&shape->matrl.color, color);
	shape->matrl.ambient = 0.1;
	shape->matrl.diffuse = 0.9;
	shape->matrl.shininess = 200;
	shape->matrl.specular = 0.9;
}

/*
** char **input here is a result of ft_split(line, " \t")
** ..split by white space and tab
** a line from the input file might look like this:
** 			"sp		0,5,0		5.0			225,25,25"
** input: 	 [0]	 [1]		[2]				[3]
** description:		center		diameter		RGB
**
** COLOR_CF lives in "scene.h" and it is a constant of 0.003921569 ..?!
** 
** The final goal of this f() shall be to fill in the necessary 
** t_matrix trans in which will be attached to t_shape shapes in t_scene
** we need to perform necessary calculations on matrices before the result
** The final t_matrix shall be a result of matrix_multiply() of 
** matrix_translate() by matrix_scale(). So we need temporary t_matrix structs
** to perform the calculations.
*/
typedef struct s_tmp
{
	t_sphere	*sphere;
	t_shape		*shape;
	t_tuple		centre;
	t_tuple		color;
	t_matrix	translate;
	t_matrix	scale;
}	t_tmp;

void	handle_sphere(char **input, t_scene *s, t_allshapes *all_shapes)
{
	t_tmp	tmp;
	double	diameter;
	int		i;

	/* DEBUG */
	printf("SPHERE\n");
	print_strings(input);

	init_matrix(&tmp.translate);
	init_matrix(&tmp.scale);
	/* ***** */
	tmp.shape = &s->shapes[s->shape_counter];
	i = 0;
	while (all_shapes->sphere[i].active == true && i < MAX_SPHERE)
		i++;
	tmp.sphere = &all_shapes->sphere[i];
	diameter = ft_atod(input[2]);
	set_tuple(&tmp.centre, input[1], POINT);
	set_tuple(&tmp.color, input[3], COLOR);
	scale_tuple(&tmp.color, COLOR_CF);
	activate_sphere(tmp.shape, tmp.sphere);
	matrix_with_color(tmp.shape, &tmp.color);
	mtx_translate(&tmp.translate, &tmp.centre);
	mtx_scale(&tmp.scale, diameter / 2, diameter / 2, diameter / 2);
	mtx_multiply(&tmp.shape->trans, &tmp.translate, &tmp.scale);
	s->shape_counter++;
	/* DEBUG */
	/*
	printf("TRANSLATE:\n");
	print_matrix(&tmp.translate);	
	printf("SCALE:\n");
	print_matrix(&tmp.scale);	
	printf("RESULT:\n");
	print_matrix(&tmp.shape->trans);	
	*/
}
