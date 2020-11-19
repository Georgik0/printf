/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:12:34 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 18:14:26 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_STR_H
# define MAKE_STR_H
# include "my_type.h"

void	fill_space(char *str, int start, int width);
char	*make_str_out(t_modifier *modifier, va_list *pa);
char	*make_str_c(t_modifier *modifier, va_list *pa);
char	*make_str_s(t_modifier *modifier, va_list *pa);
char	*make_str_p(t_modifier *modifier, va_list *pa);

# endif

