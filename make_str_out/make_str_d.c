/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:17:00 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/19 18:17:02 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

static char		*make_str_flag_d1(t_modifier *modifier, int size,
				char *str, char *sign)
{
	char	*zero;
	char	*space;
	char	*out;

	zero = NULL;
	space = NULL;
	out = NULL;
	if (modifier->accuracy == -1 && ((modifier->flag & FLAG_ZERO) == FLAG_ZERO))
	{
		zero = fill_zero(modifier->width - size);
		out = ft_strjoin(zero, str);
		free(str);
		free(zero);
		if (!(str = ft_strjoin(sign, out)))
			str = ft_strdup(out);
		free(out);
	}
	else
	{
		if (!(out = ft_strjoin(sign, str)))
			out = ft_strdup(str);
		free(str);
		str = help_str_d(modifier, size, out);
	}
	return (str);
}

static char		*make_str_flag_d(t_modifier *modifier, char *str, char *sign)
{
	int		size;
	char	*out;

	size = ft_strlen(str);
	if (sign != NULL)
		size++;
	if (modifier->width > size)
		out = make_str_flag_d1(modifier, size, str, sign);
	else
	{
		if (!(out = ft_strjoin(sign, str)))
		{
			out = ft_strdup(str);
			free(str);
		}
		else
			free(str);
	}
	return (out);
}

static char		*make_str_d1(t_modifier *modifier, long int arg)
{
	char	*str;
	char	*out;
	char	*zero;
	int		size;
	char	*sign;

	zero = NULL;
	sign = NULL;
	out = NULL;
	sign = make_sign_str(modifier, arg);
	if (arg < 0)
		arg = -arg;
	size = get_size_d(arg);
	if (modifier->accuracy == 0 && arg == 0)
		str = ft_calloc(1, 1);
	else
		str = ft_itoa_ll(arg);
	out = help_str_d1(modifier, size, str);
	str = make_str_flag_d(modifier, out, sign);
	free(zero);
	free(sign);
	return (str);
}

char			*make_str_d(t_modifier *modifier, va_list *pa)
{
	char		*str;
	long int	arg;

	arg = (long int)va_arg(*pa, int);
	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
		modifier->flag = modifier->flag & ~FLAG_ZERO;
	str = make_str_d1(modifier, arg);
	modifier->length = ft_strlen(str);
	return (str);
}
