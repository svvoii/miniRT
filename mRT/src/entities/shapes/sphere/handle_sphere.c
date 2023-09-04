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

#include "../../../heads_global/minirt.h"

/* DEBUG */
void	print_matrix(t_matrix *m)
{
	int	h = 0;
	int	w = 0;

	while (h < m->h)
	{
		printf("[ ");
		w = 0;
		while (w < m->w)
		{
			printf("%.1f ", m->matrix[h][w]);
			w++;
		}
		printf("]\n");
		h++;
	}
}
/* ***** */

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

void	mtx_multiply(t_matrix *res, t_matrix *m1, t_matrix *m2)
{
	int			it[3];
	int			h;
	int			w;
	int			i;

	res->h = min(m1->h, m2->h);
	res->w = min(m1->w, m2->w);
	h = 0;
	while (h < res->h)
	{
		w = 0;
		while (w < res->w)
		{
			i = 0;
			while (i < m1->w && i < m2->h)
			{
				res->matrix[h][w] += m1->matrix[h][i] * m2->matrix[i][w];
				i++;
			}
			w++;
		}
		h++;
	}
}

void	mtx_identity(t_matrix *m, int i)
{
	while (--i >= 0)
	{
		m->matrix[i][i] = 1;
	}
}

void	mtx_scale(t_matrix *m, double x, double y, double z)
{
	mtx_identity(m, M_MAX);
	m->matrix[0][0] = x;
	m->matrix[1][1] = y;
	m->matrix[2][2] = z;
}

//void	mtx_translate(t_matrix *m, double x, double y, double z)
void	mtx_translate(t_matrix *m, t_tuple *tpl)
{
	mtx_identity(m, M_MAX);
	m->matrix[0][3] = tpl->x;
	m->matrix[1][3] = tpl->y;
	m->matrix[2][3] = tpl->z;
}

/*
** char **values here is a result of ft_split(line, " \t")
** ..split by white space and tab
** a line from the input file might look like this:
** 			"sp		0,5,0		5.0			225,25,25"
** values: 	 [0]	 [1]		[2]				[3]
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

void	handle_sphere(char **values, t_scene *s, t_all_shapes *all_shapes)
{
	t_tmp	tmp;
	double	diameter;
	int		i;

	tmp.shape = &s->shapes[s->shape_counter];
	i = 0;
	while (all_shapes->sphere[i].active == true && i < MAX_SPHERE)
		i++;
	tmp.sphere = &all_shapes->sphere[i];
	diameter = ft_atod(values[2]);
	set_tuple(&tmp.centre, values[1], POINT);
	set_tuple(&tmp.color, values[3], COLOR);
	scale_tuple(&tmp.color, COLOR_CF);
	activate_sphere(tmp.shape, tmp.sphere);
	matrix_with_color(tmp.shape, &tmp.color);
	mtx_translate(&tmp.translate, &tmp.centre);
	mtx_scale(&tmp.scale, diameter / 2, diameter / 2, diameter / 2);
	mtx_multiply(tmp.shape, &tmp.translate, &tmp.scale);
	s->shape_counter++;
	/* DEBUG */
	printf("TRANSLATE:\n");
	print_matrix(&tmp.translate);	
	printf("SCALE:\n");
	print_matrix(&tmp.scale);	
	printf("RESULT:\n");
	print_matrix(&tmp.shape->trans);	
	/*
	*/
}
