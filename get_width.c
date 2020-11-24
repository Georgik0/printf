/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:32:40 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/16 15:32:43 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

int		get_width(const char *s, va_list *pa, int *i)
{
	int		width;
	char	*number;
	int		size;

	size = 0;
	width = 0;
	if (s[*i] == '*')
	{
		width = va_arg(*pa, int);
		*i = *i + 1;
		return (width);
	}
	else if (s[*i] >= '0' && s[*i] <= '9')
	{
		while (s[*i] >= '0' && s[*i] <= '9')
		{
			size++;
			*i = *i + 1;
		}
		number = ft_substr(s, *i - size, size);
		width = ft_atoi(number);
	}
	return (width);
}
