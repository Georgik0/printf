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

char	*make_str_flag_x(t_modifier *modifier, char *str)
{
	char	*zero;
	char	*space;
	int		size;

	size = ft_strlen(str);
	// printf("strlen = %d\n", size);
	if (modifier->width > size)
	{
		if (modifier->accuracy == -1 && ((modifier->flag & FLAG_ZERO) == FLAG_ZERO))
		{
			zero = fill_zero(modifier->width - size);
			str = ft_strjoin(zero, str);
		}
		else
		{
			space = fill_space_d(modifier->width - size);
			if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
				str = ft_strjoin(str, space);
			else
				str = ft_strjoin(space, str);
		}
	}
	return (str);
}

char	*make_str_x1(t_modifier *modifier, long int arg, int reg)
{
	char	*str;
	char	*zero;
	int		size;

	size = ft_get_size_x(arg);
	// printf("size = %d\n", size);
	if (modifier->accuracy == 0 && arg == 0)
		str = ft_calloc(1, 1);
	else
		str = ft_itoa_x(arg);
	if (reg == 1)
		ft_str_toupper(str);
	// printf("str = $%s$\n", str);
	if (modifier->accuracy > size)
	{
		zero = fill_zero(modifier->accuracy - size);
		str = ft_strjoin(zero, str);
	}
	str = make_str_flag_x(modifier, str);
	return (str);
}

char	*make_str_x(t_modifier *modifier, va_list *pa, int reg)
{
	char		*str;
	long int	arg;

	arg = va_arg(*pa, long int);
	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	str = make_str_x1(modifier, arg, reg);
	modifier->length = ft_strlen(str);
	return (str);
}
