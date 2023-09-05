/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:24:17 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 16:44:51 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define GNL_BUF_SIZE 10240

double	ft_atod(char *str);
int		ft_atoi(const char *str);
int		ft_isdouble(char *val);
int		ft_isnumber(char *str);
char	**ft_split(char const *s, char c);
int		ft_strequals(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	**ft_whitespaces(char const *s);

char	*get_next_line(int fd, char *line);

#endif
