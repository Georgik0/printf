/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:54:49 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/19 14:54:51 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

int		get_size_str_p(long int arg)
{
	int size;

	size = 1;
	if (arg == 0)
		return (size);
	while (arg != 0)
	{
		arg /= 16;
		size++;
	}
	return (size - 1);
}

void	make_str_p2(char *str, long int arg, int size)
{
	while (size >= 2)
	{
		if (arg % 16 == 10)
			str[size] = 'a';
		else if (arg % 16 == 11)
			str[size] = 'b';
		else if (arg % 16 == 12)
			str[size] = 'c';
		else if (arg % 16 == 13)
			str[size] = 'd';
		else if (arg % 16 == 14)
			str[size] = 'e';
		else if (arg % 16 == 15)
			str[size] = 'f';
		else
			str[size] = arg % 16 + '0';
		arg = arg / 16;
		size--;
	}
	str[0] = '0';
	str[1] = 'x';
}

char	*make_str_p1(t_modifier *modifier, long int arg)
{
	char	*str;
	char	*space;
	int		size;

	space = NULL;
	if (modifier->accuracy > -1 && arg == (long int)NULL)
		size = 2;
	else
		size = get_size_str_p(arg) + 2;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	make_str_p2(str, arg, size - 1);
	str[size] = '\0';
	if (size < modifier->width)
	{
		space = fill_space_d(modifier->width - size);
		if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			str = ft_strjoin(str, space);
		else
			str = ft_strjoin(space, str);
	}
	free(space);
	return (str);
}

char	*make_str_p(t_modifier *modifier, va_list *pa)
{
	char		*str;
	long int	arg;

	if (modifier->width < 0)
	{
		modifier->width = -(modifier->width);
		modifier->flag = modifier->flag | FLAG_MINUS;
	}
	arg = va_arg(*pa, long int);
	str = make_str_p1(modifier, arg);
	modifier->length = ft_strlen(str);
	return (str);
}
