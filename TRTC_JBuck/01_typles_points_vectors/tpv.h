#ifndef TPV_H
# define TPV_H

# include <stdbool.h>
# include <math.h>

# define EPSILON	0.00001

enum e_type
{
	VECTOR,
	POINT
};

typedef struct s_tuple
{
	double		x;
	double		y;
	double		z;
	enum e_type	type; /* either 1 for point or 0 for vector */
}	t_tuple;

/* 
** Factory Functions
*/

void	new_point(t_tuple *t, double x, double y, double z)
{
	t->x = x;
	t->y = y;
	t->z = z;
	t->type = POINT;
}
void	new_vector(t_tuple *t, double x, double y, double z)
{
	t->x = x;
	t->y = y;
	t->z = z;
	t->type = VECTOR;
}

/*
** Comparing Floating Point Numbers
*/
bool	equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

/*
** Basic operations with tuples
*/
void	add_tuples(t_tuple *new_tup, t_tuple *t_a, t_tuple *t_b)
{
	new_tup->x = t_a->x + t_b->x;
	new_tup->y = t_a->y + t_b->y;
	new_tup->z = t_a->z + t_b->z;
	if (t_a->type == VECTOR && t_b->type == VECTOR)
		new_tup->type = VECTOR;
	else
		new_tup->type = POINT;
}

void	substract_tuples(t_tuple *new_tup, t_tuple *t_a, t_tuple *t_b)
{
	new_tup->x = t_a->x - t_b->x;
	new_tup->y = t_a->y - t_b->y;
	new_tup->z = t_a->z - t_b->z;
	if ((t_a->type == VECTOR && t_b->type == VECTOR)
		|| (t_a->type == POINT && t_b->type == POINT))
		new_tup->type = VECTOR;
	else
		new_tup->type = POINT;
}

/* Negating a tuple will change the x, y amd z values, the type will stay the same! */
void	negating_tuple(t_tuple *tup)
{
	tup->x *= -1;
	tup->y *= -1;
	tup->z *= -1;
}

/*
** Scalar Multiplication and Division
*/
/* The "scalar value" scales the vector (changes its length) */
void	scalar_multiplication(t_tuple *tup, double scal)
{
	tup->x *= scal;
	tup->y *= scal;
	tup->z *= scal;
}

void	scalar_division(t_tuple *tup, double scal)
{
	tup->x /= scal;
	tup->y /= scal;
	tup->z /= scal;
}

/*
Unit vectors are vectors with a magnitude of 1. 
These are important because they only indicate the direction 
of the vector, not the scale. 
In other words, they represent a change in direction without 
altering the distance of the displacement.
Pythagorean theorem, which states that the square 
of the magnitude is the sum of the squares of its components
*/
int	magnitude(t_tuple *tup)
{
	return (sqrt((tup->x * tup->x) + (tup->y * tup->y) + (tup->z * tup->z)));
}
/*
** Normalizing tuple by dividing each component by its magnitude
*/
void	normalize(t_tuple *norm_tup, t_tuple *tup, int magnitude)
{
	norm_tup->x = tup->x / magnitude;
	norm_tup->y = tup->y / magnitude;
	norm_tup->z = tup->z / magnitude;
	norm_tup->type = tup->type;
}

/*
dot product (also called a scalar product, or inner
product) helps when intersecting rays with objects, as well
as when computing the shading on a surface. 
The dot product takes two vectors and returns a scalar value
The smaller dot product, the larger the angle between the vectors. 
A dot product of 1 means vectors are identical, 
A dot product of -1 means vectors point in opposite directions
In this f() we return (0) to indicate that passed tuples are not vectors.
*/
int	vect_dot_product(t_tuple *a, t_tuple *b)
{
	if (a->type == VECTOR && b->type == VECTOR)
		return (a->x * b->x + a->y * b->y + a->z * b->z);
	return (0);
}

/*
The cross product is another vector operation, but unlike the
dot product, it returns another vectonew vector that is 
perpendicular to both original vectorsr
*/
void	vect_cross_product(t_tuple *cross, t_tuple *a, t_tuple *b)
{
	cross->x = (a->y * b->z) - (a->z * b->y); 
	cross->y = (a->z * b->x) - (a->x * b->z);
	cross->z = (a->x * b->y) - (a->y * b->x);
}

#endif