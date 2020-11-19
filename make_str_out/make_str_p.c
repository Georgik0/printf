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

void	make_str_p2(char *str, long int arg, int start, int size)
{
	while (size >= 2)
	{
		if (arg % 16 == 10)
			str[start + size] = 'a';
		else if (arg % 16 == 11)
			str[start + size] = 'b';
		else if (arg % 16 == 12)
			str[start + size] = 'c';
		else if (arg % 16 == 13)
			str[start + size] = 'd';
		else if (arg % 16 == 14)
			str[start + size] = 'e';
		else if (arg % 16 == 15)
			str[start + size] = 'f';
		else
			str[start + size] = arg % 16 + '0';
		arg = arg / 16;
		size--;
	}
	str[start] = '0';
	str[start + 1] = 'x';
}

char	*make_str_p1(int flag, int width, long int arg)
{
	char	*str = NULL;
	int		size;

	size = get_size_str_p(arg) + 2;
	if (size >= width)
	{
		if (!(str = (char *)malloc((size + 1) * sizeof(char))))
			return (NULL);
		make_str_p2(str, arg, 0, size - 1);
		str[size] = '\0';
		// printf("str = %s\n", str);
	}
	else
	{
		if (flag == FLAG_MINUS)
		{
			if (!(str = (char *)malloc((width + 1) * sizeof(char))))
				return (NULL);
			make_str_p2(str, arg, 0, size - 1);
			fill_space(str, size, width);
		}
		else
		{
			if (!(str = (char *)malloc((width + 1) * sizeof(char))))
				return (NULL);
			fill_space(str, 0, width - size);
			make_str_p2(str, arg, width - size, size - 1);
		}
		str[width] = '\0';
	}
	return (str);
}

char	*make_str_p(t_modifier *modifier, va_list *pa)
{
	char		*str = NULL;
	long int	arg;
	int			flag;
	int			width;

	flag = modifier->flag;
	width = modifier->width;
	arg = va_arg(*pa, long int);
	// printf("arg = %lx\n", arg);
	// printf("size = %d\n", get_size_str_p(arg));
	str = make_str_p1(flag, width, arg);
	return (str);
}
