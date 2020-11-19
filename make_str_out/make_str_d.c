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

char	*make_str_d(t_modifier *modifier, int arg)
{
	char	*str;

	str = ft_itoa(arg);
	if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
		printf("-\n");
	if ((modifier->flag & FLAG_PLUS) == FLAG_PLUS)
		printf("+\n");
	if ((modifier->flag & FLAG_SPACE) == FLAG_SPACE)
		printf("$ $\n");
	if ((modifier->flag & FLAG_ZERO) == FLAG_ZERO)
		printf("0\n");
	if ((modifier->flag & FLAG_SCARP) == FLAG_SCARP)
		printf("#\n");
}

char	*make_str_d(t_modifier *modifier, va_list *pa)
{
	char	*str = NULL;
	int		arg;

	arg = va_arg(*pa, int);
	return (str);
}
