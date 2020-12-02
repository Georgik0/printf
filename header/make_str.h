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
char	*fill_space_d(int size);
char	*fill_zero(int len);
int		get_size_d(long long int arg);
int		get_size_u(unsigned int arg);
char	*make_str_out(t_modifier *modifier, va_list *pa);
char	*make_str_c(t_modifier *modifier, va_list *pa);
char	*make_str_s(t_modifier *modifier, va_list *pa);
char	*make_str_p(t_modifier *modifier, va_list *pa);
char	*make_str_d(t_modifier *modifier, va_list *pa);
char	*make_str_u(t_modifier *modifier, va_list *pa);
char	*make_str_x(t_modifier *modifier, va_list *pa, int reg);
char	*make_str_percent(t_modifier *modifier);
char	*make_sign_str(t_modifier *modifier, int arg);

#endif
