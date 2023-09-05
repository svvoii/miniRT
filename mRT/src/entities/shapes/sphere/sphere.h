/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 14:21:07 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../../../../includes/minirt.h"

void	handle_sphere(char **values, t_scene *s, t_allshapes *all_shapes);

/*

typedef struct sphere
{
	bool	active;
	t_tuple	centre;
}	t_sphere;

t_tuple		*nsphere_normal_at(t_tuple *p, t_matrix *m);
t_sphere	*nsphere_nsphere(t_tuple *centre);
t_sphere	*nsphere_unit(t_tuple *centre);
void		nsphere_free(t_sphere *s);

//handle_sphere.c 
void	activate_sphere(t_shape *shape, t_sphere *sphere);
void	matrix_with_color(t_shape *shape, t_tuple *color);
void	mtx_multiply(t_matrix *res, t_matrix *m1, t_matrix *m2);
void	mtx_identity(t_matrix *m, int i);
void	mtx_scale(t_matrix *m, double x, double y, double z);
void	mtx_translate(t_matrix *m, t_tuple *tpl);
//void	handle_sphere(char **values, t_scene *s, t_all_shapes *all_shapes);
*/

#endif
