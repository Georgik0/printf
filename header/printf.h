/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:41:46 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/13 18:41:50 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "bit.h"
# include "../libft/libft.h"
# include "make_str.h"
# include "my_type.h"

int				get_flags(const char *s, int *i);
int				parser(const char *s, va_list *ap);
int				get_width(const char *s, va_list *pa, int *i);
int				get_accuracy(const char *s, int *i, va_list *pa);
int				get_cpecifier(const char *s, int *i);
char			get_type(const char *s, int *i);
int				ft_printf(const char *format, ...);

#endif
