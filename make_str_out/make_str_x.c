/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:27:50 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/21 18:30:08 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

char	*make_str_flag_x1(t_modifier *modifier, char *str, int size)
{
	char	*str1;
	char	*zero;
	char	*space;

	str1 = NULL;
	if (modifier->accuracy == -1 &&
	((modifier->flag & FLAG_ZERO) == FLAG_ZERO))
	{
		zero = fill_zero(modifier->width - size);
		str1 = ft_strjoin(zero, str);
		free(zero);
		free(str);
	}
	else
	{
		space = fill_space_d(modifier->width - size);
		if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			str1 = ft_strjoin(str, space);
		else
			str1 = ft_strjoin(space, str);
		free(space);
		free(str);
	}
	return (str1);
}

char	*make_str_flag_x(t_modifier *modifier, char *str)
{
	char	*str1;
	int		size;

	size = ft_strlen(str);
	str1 = NULL;
	if (modifier->width > size)
	{
		str1 = make_str_flag_x1(modifier, str, size);
		return (str1);
	}
	return (str);
}

char	*make_str_x2(t_modifier *modifier, char *str, int size)
{
	char	*zero;
	char	*out;

	zero = NULL;
	if (modifier->accuracy > size)
	{
		zero = fill_zero(modifier->accuracy - size);
		out = ft_strjoin(zero, str);
		free(zero);
		free(str);
		return (out);
	}
	return (str);
}

char	*make_str_x1(t_modifier *modifier, unsigned int arg, int reg)
{
	char	*str;
	char	*str1;
	char	*str2;
	int		size;

	str1 = NULL;
	str2 = NULL;
	size = ft_get_size_x(arg);
	if (modifier->accuracy == 0 && arg == 0)
		str = ft_calloc(1, 1);
	else
		str = ft_itoa_x(arg);
	if (reg == 1)
		ft_str_toupper(str);
	str1 = make_str_x2(modifier, str, size);
	str2 = make_str_flag_x(modifier, str1);
	return (str2);
}

char	*make_str_x(t_modifier *modifier, va_list *pa, int reg)
{
	char				*str;
	unsigned int		arg;

	arg = (unsigned int)va_arg(*pa, unsigned int);
	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	str = make_str_x1(modifier, arg, reg);
	modifier->length = ft_strlen(str);
	return (str);
}
