/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_str_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:30:33 by skitsch           #+#    #+#             */
/*   Updated: 2020/12/03 16:30:38 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

char		*help_str_d(t_modifier *modifier, int size, char *out)
{
	char	*space;
	char	*str;

	str = NULL;
	space = fill_space_d(modifier->width - size);
	if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
		str = ft_strjoin(out, space);
	else
		str = ft_strjoin(space, out);
	free(space);
	free(out);
	return (str);
}

char		*help_str_d1(t_modifier *modifier, int size, char *str)
{
	char	*zero;
	char	*out;

	out = NULL;
	zero = NULL;
	if (modifier->accuracy > size)
	{
		zero = fill_zero(modifier->accuracy - size);
		out = ft_strjoin(zero, str);
		free(zero);
	}
	else
		out = ft_strdup(str);
	free(str);
	return (out);
}
