/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/08 13:13:06 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "../../../includes/minirt.h"

/* handle_matrix.c */
void	mtx_identity(t_matrix *m, int i);
void	mtx_scale(t_matrix *m, double x, double y, double z);
void	mtx_translate(t_matrix *m, t_tuple *tpl);
void	mtx_multiply(t_matrix *res, t_matrix *m1, t_matrix *m2);
void	view_transform(t_camera *cam, t_tuple *to, t_tuple *up);

void	tuple_to_matrix(t_matrix *m, t_tuple *t);

/* matrix_advanced_1.c */
double	matrix_determinant(t_matrix *m);

/* matrix_advanced_2.c */
void	tuple_apply_trans_matrix(t_tuple *resut, t_matrix *invtd, t_tuple *tup);

/* matrix_advanced_3.c */


/* DEBUG */
void	print_matrix(t_matrix *m);


#endif
