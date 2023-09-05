/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 15:33:47 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "../../../includes/minirt.h"

/* handle_tuple.c */
void	set_tuple(t_tuple *tuple, char *value, e_tuple type);
void	scale_tuple(t_tuple *t, double scale);
void	add_tuples(t_tuple *dest, t_tuple *t1, t_tuple *t2);
void	copy_tuple(t_tuple *dest, t_tuple *from);
void	substract_tuple(t_tuple *dest, t_tuple *t1, t_tuple *t2);
void	normalize_tuple(t_tuple *norm, t_tuple *t);
void	cross_product_tuple(t_tuple *cros_p, t_tuple *t1, t_tuple *t2);
void	negate_tuple(t_tuple *t);

/* tuple_basic.c */
int	is_tuple(char *value, int exclude_neg);

/*
# define IS_POINT    1
# define IS_VECTOR   0

typedef enum
{
	VECTOR,
	POINT,
	COLOR
}	e_tuple;

typedef struct tuple
{
	double	x;
	double	y;
	double	z;
	e_tuple	type;
}	t_tuple;
int		is_tuple(char *value, int exclude_neg);

t_tuple	*tuple_vector(double x, double y, double z);
t_tuple	*tuple_point(double x, double y, double z);
t_tuple	*tuple_color(double r, double g, double b);

void	tuple_free(t_tuple *tuple);

int		tuple_is_vector(t_tuple *tuple);

int		tuple_equals(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_add(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_substract(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_scalar_multiply(t_tuple *t, double scale);
t_tuple	*tuple_negate(t_tuple *t);
double	tuple_length(t_tuple *t);
t_tuple	*tuple_normalize(t_tuple *t);
double	tuple_dot_product(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_cross_product(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_multiply(t_tuple *t1, t_tuple *t2);
t_tuple	*tuple_reflect(t_tuple *v_in, t_tuple *v_normal);
t_tuple	*tuple_copy(t_tuple *t);

// handle_tuple.c
void	set_tuple(t_tuple *tuple, char *value, e_tuple type);
void	scale_tuple(t_tuple *t, double scale);
void	copy_tuple(t_tuple *dest, t_tuple *from);
void	add_tuples(t_tuple *dest, t_tuple *t1, t_tuple *t2);
void	substract_tuple(t_tuple *dest, t_tuple *t1, t_tuple *t2);
void	normalize_tuple(t_tuple *norm, t_tuple *t);
void	cross_product_tuple(t_tuple *cros_p, t_tuple *t1, t_tuple *t2);
void	negate_tuple(t_tuple *t);

*/
#endif 