/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/08 14:50:26 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "../../../includes/minirt.h"

/* colors_get.c */


/* colors_set.c */
unsigned int	make_argb(unsigned char r, unsigned char g, unsigned char b);

/*
void			set_red(unsigned int *rgb, unsigned char red);
void			set_green(unsigned int *rgb, unsigned char green);
void			set_blue(unsigned int *rgb, unsigned char blue);
unsigned char	get_red(unsigned int rgb);
unsigned char	get_green(unsigned int rgb);
unsigned char	get_blue(unsigned int rgb);
unsigned int	make_rgb(unsigned char r, unsigned char g, unsigned char b);
unsigned int	tuple_to_rgb(t_tuple *rgb_tuple);
unsigned int	tuple_to_argb(t_tuple *rgb_tuple);
unsigned int	make_argb(unsigned char r, unsigned char g, unsigned char b);
*/

#endif //RT_CHALLENGE_COLORS_H
