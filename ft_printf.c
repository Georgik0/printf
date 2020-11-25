/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:58:43 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/13 17:59:53 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*str;
	int			out;

	va_start(ap, format);
	if ((out = parser(format, &ap)) == -1)
		return (-1);
	str = va_arg(ap, char*);
	va_end(ap);
	return (out);
}
