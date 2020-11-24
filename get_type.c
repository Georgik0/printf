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
	char	type;

	if (s[*i] == 'c')
		type = 'c';
	if (s[*i] == 's')
		type = 's';
	if (s[*i] == 'p')
		type = 'p';
	if (s[*i] == 'd')
		type = 'd';
	if (s[*i] == 'i')
		type = 'i';
	if (s[*i] == 'u')
		type = 'u';
	if (s[*i] == 'x')
		type = 'x';
	if (s[*i] == 'X')
		type = 'X';
	if (s[*i] == '%')
		type = '%';
	if (s[*i] == 'n')
		type = 'n';
	if (s[*i] == 'f')
		type = 'f';
	if (s[*i] == 'g')
		type = 'g';
	if (s[*i] == 'e')
		type = 'e';
	return (type);
}
