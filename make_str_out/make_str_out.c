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
	else if (modifier->type == 'd' || modifier->type == 'i')
		return (make_str_d(modifier, pa));
	else if (modifier->type == 'u')
		return (make_str_u(modifier, pa));    // Править itoa_u
	else if (modifier->type == 'x')
		return (make_str_x(modifier, pa, 0));
	else if (modifier->type == 'X')
		return (make_str_x(modifier, pa, 1));
	else if (modifier->type == '%')
		return (make_str_percent(modifier));
	// else if (modifier->type == 'n')
	// else if (modifier->type == 'f')
	// else if (modifier->type == 'g')
	// else if (modifier->type == 'e')
	return (NULL);
}
