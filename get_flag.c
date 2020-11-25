/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:22:15 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/16 12:22:18 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

int	get_flags(const char *s, int *i)
{
	int flag;

	flag = FLAG_OUT;
	while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-' || s[*i] == '0' ||
	s[*i] == '#')
	{
		if (s[*i] == ' ')
			flag = flag | FLAG_SPACE;
		else if (s[*i] == '+')
			flag = flag | FLAG_PLUS;
		else if (s[*i] == '-')
			flag = flag | FLAG_MINUS;
		else if (s[*i] == '0')
			flag = flag | FLAG_ZERO;
		else if (s[*i] == '#')
			flag = flag | FLAG_SCARP;
		else
			return (flag);
		*i = *i + 1;
	}
	return (flag);
}
