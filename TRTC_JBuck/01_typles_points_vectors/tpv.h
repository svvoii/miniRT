#ifndef TPV_H
# define TPV_H

# include <stdio.h>
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


void	new_point(t_tuple *t, double x, double y, double z);
void	new_vector(t_tuple *t, double x, double y, double z);
bool	equal(double a, double b);
void	add_tuples(t_tuple *new_tup, t_tuple *t_a, t_tuple *t_b);
void	substract_tuples(t_tuple *new_tup, t_tuple *t_a, t_tuple *t_b);
void	negating_tuple(t_tuple *tup);
void	scalar_multiplication(t_tuple *tup, double scal);
void	scalar_division(t_tuple *tup, double scal);
int		magnitude(t_tuple *tup);
void	normalize(t_tuple *norm_tup, t_tuple *tup, int magnitude);
int		vect_dot_product(t_tuple *a, t_tuple *b);
void	vect_cross_product(t_tuple *cross, t_tuple *a, t_tuple *b);

#endif