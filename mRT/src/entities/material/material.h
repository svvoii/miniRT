/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 10:26:26 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

/*
# include "../../../heads_global/minirt.h"

typedef struct matrl
{
	t_tuple	color;
	double	diffuse;
	double	ambient;
	double	specular;
	double	shininess;
}	t_matrl;
typedef struct matrl
{
	t_tuple	*color;
	double	diffuse;
	double	ambient;
	double	specular;
	double	shininess;
}	t_matrl;
typedef struct lightning_pack
{
	t_matrl	*m;
	t_light	*l;
	t_tuple	*posit;
	t_tuple	*eye_v;
	t_tuple	*norm_v;
	t_tuple	*ef_color;
	t_tuple	*lightv;
	t_tuple	*diffuse;
	t_tuple	*specular;
	t_tuple	*reflv;
	double	rf_dot_eye;
	double	light_dot_norm;
}	t_lightning_pack;

void				material_free(t_matrl *m);
t_tuple				*lightning(t_lightning_pack *p, int in_shadow);
void				cleanup_light_pack(t_lightning_pack *l);
t_matrl				*mat_with_col(t_tuple *color);
*/

#endif //RT_CHALLENGE_MATERIAL_H
