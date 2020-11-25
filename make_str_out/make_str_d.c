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

static char		*make_sign_str(t_modifier *modifier, int arg)
{
	char	*sign;

	if (!(sign = (char *)malloc(2 * sizeof(char))))
		return (NULL);
	if (arg < 0)
		sign[0] = '-';
	else if (((modifier->flag & FLAG_PLUS) == FLAG_PLUS) && arg > 0)
		sign[0] = '+';
	else
	{
		free(sign);
		return (NULL);
	}
	sign[1] = '\0';
	return (sign);
}

static char		*make_str_flag_d1(t_modifier *modifier, int size,
				char *str, char *sign)
{
	char	*zero;
	char	*space;

	zero = NULL;
	space = NULL;
	if (modifier->accuracy == -1 && ((modifier->flag & FLAG_ZERO) == FLAG_ZERO))
	{
		zero = fill_zero(modifier->width - size);
		str = ft_strjoin(zero, str);
		str = ft_strjoin(sign, str) == NULL ? str : ft_strjoin(sign, str);
	}
	else
	{
		str = ft_strjoin(sign, str) == NULL ? str : ft_strjoin(sign, str);
		space = fill_space_d(modifier->width - size);
		if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			str = ft_strjoin(str, space);
		else
			str = ft_strjoin(space, str);
	}
	free(zero);
	free(space);
	return (str);
}

static char		*make_str_flag_d(t_modifier *modifier, char *str, char *sign)
{
	int		size;

	size = ft_strlen(str);
	if (sign != NULL)
		size++;
	if (modifier->width > size)
		str = make_str_flag_d1(modifier, size, str, sign);
	else
		str = ft_strjoin(sign, str) == NULL ? str : ft_strjoin(sign, str);
	return (str);
}

static char		*make_str_d1(t_modifier *modifier, long int arg)
{
	char	*str;
	char	*zero;
	int		size;
	char	*sign;

	zero = NULL;
	sign = NULL;
	sign = make_sign_str(modifier, arg);
	if (arg < 0)
		arg = -arg;
	size = get_size_d(arg);
	if (modifier->accuracy == 0 && arg == 0)
		str = ft_calloc(1, 1);
	else
		str = ft_itoa_ll(arg);
	if (modifier->accuracy > size)
	{
		zero = fill_zero(modifier->accuracy - size);
		str = ft_strjoin(zero, str);
	}
	str = make_str_flag_d(modifier, str, sign);
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
