/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:21:58 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/18 17:22:00 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

char	*make_str_s2(t_modifier *modifier, const char *arg)
{
	char	*str;

	if (modifier->accuracy < (int)ft_strlen(arg) && modifier->accuracy >= 0)
	{
		if (!(str = (char *)malloc((modifier->accuracy + 1) * sizeof(char))))
			return (NULL);
		ft_strlcpy(str, arg, modifier->accuracy + 1);
	}
	else
		str = ft_strdup(arg);
	return (str);
}

char	*make_str_s1(t_modifier *modifier, const char *arg)
{
	char		*str;
	char		*str1;
	const char	*space;
	int			len_str;

	str1 = NULL;
	if (arg == NULL)
		arg = "(null)";
	str = make_str_s2(modifier, arg);
	len_str = ft_strlen(str);
	if (modifier->width > len_str)
	{
		space = fill_space_d(modifier->width - len_str);
		if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			str1 = ft_strjoin(str, space);
		else
			str1 = ft_strjoin(space, str);
		free((char *)str);
		free((char *)space);
		return (str1);
	}
	return (str);
}

char	*make_str_s(t_modifier *modifier, va_list *pa)
{
	char			*str;
	const char		*arg;

	arg = va_arg(*pa, const char*);
	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	str = make_str_s1(modifier, arg);
	modifier->length = ft_strlen(str);
	return (str);
}
