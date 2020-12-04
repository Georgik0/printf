/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_accuracy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:06:44 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 14:06:46 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

static int		get_accuracy1(const char *s, char *number, int accuracy, int *i)
{
	int		size;

	size = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		*i = *i + 1;
		size++;
	}
	number = ft_substr(s, *i - size, size);
	accuracy = ft_atoi(number);
	free(number);
	return (accuracy);
}

int				get_accuracy(const char *s, int *i, va_list *pa)
{
	int		accuracy;
	char	*number;

	number = NULL;
	accuracy = -1;
	if (s[*i] == '.')
	{
		accuracy = 0;
		*i = *i + 1;
		if (s[*i] == '*')
		{
			accuracy = va_arg(*pa, int);
			*i = *i + 1;
			if (accuracy < 0)
				return (-1);
			return (accuracy);
		}
		else if (s[*i] >= '0' && s[*i] <= '9')
			accuracy = get_accuracy1(s, number, accuracy, i);
	}
	return (accuracy);
}
