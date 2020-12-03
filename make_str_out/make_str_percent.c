/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:22:10 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/23 14:23:27 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

char	*make_str_percent1(t_modifier *modifier, char *str)
{
	char	*zero;
	char	*space;
	char	*out;

	out = NULL;
	if (modifier->width > 1)
	{
		zero = fill_zero(modifier->width - 1);
		space = fill_space_d(modifier->width - 1);
		if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			out = ft_strjoin(str, space);
		else
		{
			if ((modifier->flag & FLAG_ZERO) == FLAG_ZERO)
				out = ft_strjoin(zero, str);
			else
				out = ft_strjoin(space, str);
		}
		free(str);
		free(zero);
		free(space);
		return (out);
	}
	return (str);
}

char	*make_str_percent(t_modifier *modifier)
{
	char	*str;
	char	*out;

	out = NULL;
	if (!(str = (char *)ft_calloc(1, 2)))
		return (NULL);
	str[0] = '%';
	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	out = make_str_percent1(modifier, str);
	modifier->length = ft_strlen(out);
	return (out);
}
