/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:14:43 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 16:14:47 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

char	get_type(const char *s, int *i)
{
	if (s[*i] == 'c')
		return ('c');
	if (s[*i] == 's')
		return ('s');
	if (s[*i] == 'p')
		return ('p');
	if (s[*i] == 'd')
		return ('d');
	if (s[*i] == 'i')
		return ('i');
	if (s[*i] == 'u')
		return ('u');
	if (s[*i] == 'x')
		return ('x');
	if (s[*i] == 'X')
		return ('X');
	if (s[*i] == '%')
		return ('%');
	if (s[*i] == 'n')
		return ('n');
	if (s[*i] == 'f')
		return ('f');
	if (s[*i] == 'g')
		return ('g');
	if (s[*i] == 'e')
		return ('e');
	return (0);
}
