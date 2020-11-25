/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cpecifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:45:26 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 14:45:28 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

static int	get_cpecifier1(const char *s, int *i, int cpecifier)
{
	if (s[*i] == 'l' && s[*i] != 'l')
	{
		cpecifier = cpecifier | CPECIFIER_L;
	}
	else if (s[*i] == 'l' && s[*i] == 'l')
	{
		cpecifier = cpecifier | CPECIFIER_LL;
		*i = *i + 1;
	}
	else if (s[*i] == 'h' && s[*i] != 'h')
	{
		cpecifier = cpecifier | CPECIFIER_H;
	}
	else if (s[*i] == 'h' && s[*i] == 'h')
	{
		cpecifier = cpecifier | CPECIFIER_HH;
		*i = *i + 1;
	}
	return (cpecifier);
}

int			get_cpecifier(const char *s, int *i)
{
	int	cpecifier;

	cpecifier = CPECIFIER_OUT;
	while (s[*i] == 'l' || s[*i] == 'h')
	{
		cpecifier = get_cpecifier1(s, i, cpecifier);
		*i = *i + 1;
	}
	return (cpecifier);
}
