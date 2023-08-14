#include "tpv.h"

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_projectile;

typedef struct s_environment
{
	t_tuple	grvity;
	t_tuple	wind;
}	t_environment;

void	tick(t_environment *env, t_projectile *proj)
{
}

int	main()
{
	t_tuple			test_vector;
	t_tuple			norm_vect;
	t_projectile	projectile;
	int		i;

	new_vector(&test_vector, 1, 1, 0);
	normalize(&norm_vect, &test_vector, magnitude(&test_vector));
	i = 0;

	return (0);
}
