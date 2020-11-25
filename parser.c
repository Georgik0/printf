/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:30:55 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/14 17:30:57 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

static void			make_write(const char *s, int *len, int *i)
{
	while (s[*i] != '%' && s[*i])
	{
		*len = *len + 1;
		write(1, &s[*i], 1);
		*i = *i + 1;
	}
	return ;
}

static t_modifier	*get_modifier(const char *s, t_modifier *modifier,
					int *i, va_list *pa)
{
	*i = *i + 1;
	modifier->flag = get_flags(s, i);
	modifier->width = get_width(s, pa, i);
	modifier->accuracy = get_accuracy(s, i, pa);
	modifier->specifier = get_cpecifier(s, i);
	modifier->type = get_type(s, i);
	return (modifier);
}

static int			parser1(const char *s, va_list *pa, t_modifier *modifier)
{
	int			len;
	int			i;
	char		*str;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			make_write(s, &len, &i);
		if (s[i] == '%' && s[i])
			modifier = get_modifier(s, modifier, &i, pa);
		if (s[i] == '\0')
			return (len);
		str = make_str_out(modifier, pa);
		len = len + modifier->length;
		ft_putstr_fd(str, 1);
		free(str);
		i++;
	}
	return (len);
}

int					parser(const char *s, va_list *pa)
{
	int			len;
	t_modifier	*modifier;

	if (!(modifier = (t_modifier*)malloc(sizeof(t_modifier))))
	{
		va_end(*pa);
		return (-1);
	}
	len = parser1(s, pa, modifier);
	free(modifier);
	return (len);
}
