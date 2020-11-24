/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:07:56 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 18:08:00 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

void	make_str_c2(char arg, t_modifier *modifier)
{
	char	*space;

	space = NULL;
	ft_putchar_fd(arg, 1);
	if ((modifier->width) > 1)
	{
		space = fill_space_d(modifier->width - 1);
		ft_putstr_fd(space, 1);
		modifier->length = ft_strlen(space) + 1;
		free(space);
	}
	else
		modifier->length = 1;
}

void	make_str_c3(char arg, t_modifier *modifier)
{
		char	*space;

	space = NULL;
	if (modifier->width > 1)
	{
		space = fill_space_d(modifier->width - 1);
		ft_putstr_fd(space, 1);
		modifier->length = ft_strlen(space) + 1;
		free(space);
	}
	else
		modifier->length = 1;
	ft_putchar_fd(arg, 1);
}

char		*make_str_c(t_modifier *modifier, va_list *pa)
{
	char		*str;
	char		arg;

	str = NULL;
	arg = va_arg(*pa, int);
	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	if (modifier->width != 0)
	{
		if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			make_str_c2(arg, modifier);
		else
			make_str_c3(arg, modifier);
	}
	else
	{
		ft_putchar_fd(arg, 1);
		modifier->length = 1;
	}
	return (str);
}
