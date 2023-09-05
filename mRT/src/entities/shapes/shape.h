/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/01 14:12:18by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H
/*
# include "../../../heads_global/minirt.h"

typedef enum
{
	NONE,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
	CONE,
	CUBE
}	e_type;

** Using enum e_type to define the shape type
** void *shape will hold a pointer to a particular 
** shape structure given in e_type and will be 
** initialized to NULL if type is NONE.
typedef struct shape
{
	e_type		type;
	t_matrl		matrl;
	t_matrix	trans;
	void		*shape;
}	t_shape;
*/

/*
typedef struct shape
{
	char		type;
	t_matrl		*matrl;
	t_matrix	*trans;
	void		*shape;
}	t_shape;
//t_shape	*make_shape(char type, void *shape_itself);
t_shape	*make_shape(e_type type, void *shape_itself);
void	*set_transform(t_shape *sh, t_matrix *trans);
t_tuple	*shape_normal_at(t_shape *sh, t_tuple *p);
void	free_shape(t_shape *s);
*/

#endif