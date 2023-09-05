/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 14:48:17 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
** Takes a pointer to t_tuple instance, char * to an input values of 3 doubles
** and a type of the given tuple which is set in e_tuple
** type VECTOR = 0
** type POINT = 1
** type COLOR = 2
*/
// previous name: t_tuple	*get_tuple(char *value, char type)
void	set_tuple(t_tuple *tuple, char *value, e_tuple type)
{
	char	**input;

	input = ft_split(value, ',');
	tuple->x = ft_atod(input[0]);
	tuple->y = ft_atod(input[1]);
	tuple->z = ft_atod(input[2]);
	tuple->type = type;
}

/*
** Simply multiplies the value of the given t_tuple, usualy color by the scale
*/
//previous name: t_tuple	*tuple_scalar_multiply(t_tuple *t, double scale)
void	scale_tuple(t_tuple *t, double scale)
{
	t->x *= scale;
	t->y *= scale;
	t->z *= scale;
}

/*
** Since a tuple e_type can be either: 
** VECTOR = 0, POINT = 1 or COLOR = 2
** we have control statement that assignes COLOR type 
** if either of tuples is of type COLOR
** if both t1 and t2 are of type POINT the resulting dest shall be POINT as well
** Otherwise if both t1 and t2 are of type VECTOR resulting dest will be VECTOR as well
** ..if one is a POINT and otehr is VECTOR the result will be a POINT
*/
void	add_tuples(t_tuple *dest, t_tuple *t1, t_tuple *t2)
{
	dest->x = t1->x + t2->x;
	dest->y = t1->y + t2->y;
	dest->z = t1->z + t2->z;
	if (t1->type == COLOR || t2->type == COLOR)
		dest->type = COLOR;
	else if (t1->type == POINT && t2->type == POINT)
		dest->type = POINT;
	else
		dest->type = t1->type + t2->type;
}

void	copy_tuple(t_tuple *dest, t_tuple *from)
{
	from->type = dest->type;
	from->x = dest->x;
	from->y = dest->y;
	from->z = dest->z;
}

/*
** VECTOR = 0, POINT = 1 or COLOR = 2
** ..it is not clear what is the type shall be when substracting
** VECTOR - POINT = -1.. ?!
*/
void	substract_tuple(t_tuple *dest, t_tuple *t1, t_tuple *t2)
{
	dest->x = t1->x - t2->x;
	dest->y = t1->y - t2->y;
	dest->z = t1->z - t2->z;
	if (t1->type == COLOR || t2->type == COLOR)
		dest->type = COLOR;
	else if (t1->type == VECTOR && t2->type == POINT)
		dest->type = t1->type - t2->type; // ???
	else
		dest->type = t1->type - t2->type;
		//dest->type = abs(t1->type - t2->type);
}

double	length_tuple(t_tuple *t)
{
	return (
		sqrt(
			t->x * t->x
			+ t->y * t->y
			+ t->z * t->z
			+ t->type * t->type)
	);
}

void	normalize_tuple(t_tuple *norm, t_tuple *t)
{
	double	length;

	length = length_tuple(t);
	norm->x = t->x / length;
	norm->y = t->y / length;
	norm->z = t->z / length;
	norm->type = t->type;
}

/*
** cross product tuple type shall be a VECTOR
*/
void	cross_product_tuple(t_tuple *cros_p, t_tuple *t1, t_tuple *t2)
{
	cros_p->x = t1->y * t2->z - t1->z * t2->y;
	cros_p->y = t1->z * t2->x - t1->x * t2->z; 
	cros_p->z = t1->x * t2->y - t1->y * t2->x; 
	cros_p->type = VECTOR;
}

/*
** Negate operation is usualy applied to a VECTOR 
** VECTOR = 0, so changing the type is not necessary
*/
void	negate_tuple(t_tuple *t)
{
	t->x *= -1;
	t->y *= -1;
	t->z *= -1;
	//t->type *= -1;
}
