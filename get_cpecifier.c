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

int		get_cpecifier(const char *s, int *i)
{
	int	cpecifier;

	cpecifier = CPECIFIER_OUT;
	while (s[*i] == 'l' || s[*i] == 'h')
	{
		//printf("s = %c\n", s[*i]);
		if (s[*i] == 'l' && s[*i] != 'l')
		{
			cpecifier = cpecifier | CPECIFIER_l;
		}
		else if (s[*i] == 'l' && s[*i] == 'l')
		{
			cpecifier = cpecifier | CPECIFIER_ll;
			*i = *i + 1;
		}
		else if (s[*i] == 'h' && s[*i] != 'h')
		{
			cpecifier = cpecifier | CPECIFIER_h;
		}
		else if (s[*i] == 'h' && s[*i] == 'h')
		{
			cpecifier = cpecifier | CPECIFIER_hh;
			*i = *i + 1;
			//printf("s = %c\n", s[*i]);
		}
		*i = *i + 1;
		//printf("s = %c\n", s[*i]);
	}
	return (cpecifier);
}
