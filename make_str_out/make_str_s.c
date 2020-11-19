/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:21:58 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/18 17:22:00 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

void	fill_space_s(char *str, int start, int width)
{
	while (start < width)
	{
		str[start] = ' ';
		start++;
	}
}

char	*make_str_s1(int len, const char *arg, int width, int flag)
{
	char *str;

	str = NULL;
	if (len - 1 < width)
	{
		if (!(str = (char *)malloc(width * sizeof(char))))
			return (NULL);
		if (flag == FLAG_MINUS)
		{
			ft_strlcpy(str, arg, len);
			fill_space_s(str, len - 1, width);
		}
		else
		{
			fill_space_s(str, 0, width - len + 1);
			ft_strlcpy(str + width - len + 1, arg, len);
		}
		// printf("%s", str);
	}
	else
	{
		if (!(str = (char *)malloc(len * sizeof(char))))
			return (NULL);
		ft_strlcpy(str, arg, len);
	}
	return (str);
}

char	*make_str_s(t_modifier *modifier, va_list *pa)
{
	int				flag;
	int				width;//ширина
	int				len;
	char			*str;
	const char		*arg;

	flag = modifier->flag;
	width = modifier->width;
	str = NULL;
	arg = va_arg(*pa, const char*);
	// printf("arg = %s\n", arg);
	len = ft_strlen(arg) + 1;
	// printf("len = %d\n", len);
	if (width != 0)
		str = make_str_s1(len, arg, width, flag);
	else
	{
		if (!(str = (char *)malloc(len * sizeof(char))))
			return (NULL);
		ft_strlcpy(str, arg, len);
	}
	return (str);
}
