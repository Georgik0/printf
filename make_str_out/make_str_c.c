/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:07:56 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 18:08:00 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

void	fill_space_str(char *str, int len)
{
	while (len >= 0)
	{
		str[len] = ' ';
		len--;
	}
}

char	*make_str_c1(char *str, char arg)
{
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	// printf("$test$");
	str[0] = arg;
	str[1] = '\0';
	// printf("str = %s", str);
	return (str);
}

char	*make_str_c2(char *str, char arg, int width)
{
	int i;

	if (!(str = (char *)malloc(sizeof(char) * (width + 1))))
		return (NULL);
	// printf("$test$");
	str[0] = arg;
	i = 1;
	while (i < width)
	{
		str[i] = ' ';
		i++;
	}
	str[width] = '\0';
	// printf("str = %s", str);
	return (str);
}

char		*make_str_c(t_modifier *modifier, va_list *pa)
{
	int			flag;
	int			width;//ширина
	char		*str;
	char		arg;

	flag = modifier->flag;
	width = modifier->width;
	str = NULL;
	arg = va_arg(*pa, int);
	// printf("arg = %c", arg);
	// printf("width = %d", width);
	if (width != 0)
	{
		if (flag == FLAG_MINUS)
			str = make_str_c2(str, arg, width);
		else
		{
			if (!(str = (char *)malloc(sizeof(char) * (width + 1))))
				return (NULL);
			str[width - 1] = arg;
			fill_space_str(str, width - 2);
			str[width] = '\0';
		}
	}
	else
		str = make_str_c1(str, arg);
	// printf("str = %s", str);
	return (str);
}
