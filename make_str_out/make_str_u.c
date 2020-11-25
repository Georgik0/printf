/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:50:02 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/20 18:52:05 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

static char		*make_str_flag_u1(t_modifier *modifier, char *str, int size)
{
	char	*zero;
	char	*space;

	zero = NULL;
	space = NULL;
	if (modifier->accuracy == -1 &&
	((modifier->flag & FLAG_ZERO) == FLAG_ZERO))
	{
		zero = fill_zero(modifier->width - size);
		str = ft_strjoin(zero, str);
		free(zero);
	}
	else
	{
		space = fill_space_d(modifier->width - size);
		if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			str = ft_strjoin(str, space);
		else
			str = ft_strjoin(space, str);
		free(space);
	}
	return (str);
}

static char		*make_str_flag_u(t_modifier *modifier, char *str)
{
	int		size;

	size = ft_strlen(str);
	if (modifier->width > size)
		str = make_str_flag_u1(modifier, str, size);
	return (str);
}

static char		*make_str_u1(t_modifier *modifier, unsigned int arg)
{
	char	*str;
	char	*zero;
	int		size;
	char	*sign;

	zero = NULL;
	sign = NULL;
	size = get_size_u(arg);
	if (modifier->accuracy == 0 && arg == 0)
		str = ft_calloc(1, 1);
	else
		str = ft_itoa_u(arg);
	if (modifier->accuracy > size)
	{
		zero = fill_zero(modifier->accuracy - size);
		str = ft_strjoin(zero, str);
	}
	str = ft_strjoin(sign, str) == NULL ? str : ft_strjoin(sign, str);
	str = make_str_flag_u(modifier, str);
	free(zero);
	free(sign);
	return (str);
}

char			*make_str_u(t_modifier *modifier, va_list *pa)
{
	char			*str;
	unsigned int	arg;

	arg = (unsigned int)va_arg(*pa, unsigned int);
	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	str = make_str_u1(modifier, arg);
	modifier->length = ft_strlen(str);
	return (str);
}
