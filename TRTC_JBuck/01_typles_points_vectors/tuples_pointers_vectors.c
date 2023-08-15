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

void	tick(t_projectile *new_proj, t_environment *env, t_projectile *proj)
{
	t_tuple	tmp; 

	add_tuples(&new_proj->position, &proj->position, &proj->velocity);
	/* addint two tuples before adding again into new proj.. */
	add_tuples(&tmp, &env->grvity, &env->wind);
	add_tuples(&new_proj->velocity, &proj->velocity, &tmp);
}

int	main()
{
	t_projectile	projectile;
	t_tuple			tmp_vector; 
	/*
	tmp_vector is uset to compute gravity and wind and plug it in new_projectile
	as velosity tuple with calculated magnitude
	*/
	t_environment	env;
	int		i;

	new_point(&projectile.position, 0, 1, 0);
	new_vector(&tmp_vector, 1, 1, 0);
	normalize(&projectile.velocity, &tmp_vector, magnitude(&tmp_vector));

	new_vector(&env.grvity, 0, -0.1, 0);
	new_vector(&env.wind, -0.01, 0, 0);
	i = 0;
	while (projectile.position.y >= 0)
	{
		tick(&projectile, &env, &projectile);
		printf("[%d]\tx:[%.2f], y:[%.2f], z:[%.2f]\n", i, projectile.position.x, projectile.position.y, projectile.position.z);
		i++;
	}

	return (0);
}
