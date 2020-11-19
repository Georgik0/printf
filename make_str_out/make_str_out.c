/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:11:14 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 17:11:16 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

char	*make_str_out(t_modifier *modifier, va_list *pa)
{
	if (modifier->type == 'c')
		return (make_str_c(modifier, pa));
	else if (modifier->type == 's')
		return (make_str_s(modifier, pa));
	else if (modifier->type == 'p')
		return (make_str_p(modifier, pa));
	else if (modifier->type == 'd')
	// else if (modifier->type == 'i')
	// else if (modifier->type == 'u')
	// else if (modifier->type == 'x')
	// else if (modifier->type == 'X')
	// else if (modifier->type == '%')
	// else if (modifier->type == 'n')
	// else if (modifier->type == 'f')
	// else if (modifier->type == 'g')
	// else if (modifier->type == 'e')
	return (NULL);
}
