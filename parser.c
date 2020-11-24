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

void	make_write(const char *s, int *len, int *i)
{
	while (s[*i] != '%' && s[*i]) // || (s[*i] == '%' && s[*i + 1] == '%'))
	{
		*len = *len + 1;
		write(1, &s[*i], 1);
		*i = *i + 1;
		// printf("\ni = %d\n", *i);
		// printf("%c", s[*i]);
		// printf("|i = %d|\n", *i);
	}
	// printf("\ni = %d    s[i] = %c\n", *i, s[*i]);
	// printf("|i = %d|", *i);
	return ;
}

int		parser(const char *s, va_list *pa)
{
	int			len;
	int			i;
	t_modifier	*modifier;
	char		*str;

	if(!(modifier = (t_modifier*)malloc(sizeof(t_modifier))))
	{
		va_end(*pa);
		return (-1);
	}
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%') // || (s[i] == '%' && s[i + 1] == '%')
		{
			// printf("|i = %d|", i);
			make_write(s, &len, &i);
			// printf("\n");
			// printf("|i = %d|", i);
		}
		// printf("\ni = %d    s[i] = %c\n", i, s[i]);
		// printf("|i = %d|", i);
		// printf(" |s[i] = %c| ", s[i]);
		// printf("\ni = %d\n", i);
		// printf("test = %c", s[i]);
		if (s[i] == '%' && s[i]) //  && s[i + 1] != '%'
		{
			// printf(" |s[i] = %c| ", s[i]);
			// printf("test");
			i++;
			modifier->flag = get_flags(s, &i);
			//--------------Проверка флагов-------------------
			// printf("flag = %d\n", modifier->flag);
			// if ((modifier->flag & FLAG_SCARP) == FLAG_SCARP)
			// 	printf("#\n");
			// if ((modifier->flag & FLAG_MINUS) == FLAG_MINUS)
			// 	printf("-\n");
			// if ((modifier->flag & FLAG_PLUS) == FLAG_PLUS)
			// 	printf("+\n");
			// if ((modifier->flag & FLAG_SPACE) == FLAG_SPACE)
			// 	printf("$ $\n");
			// if ((modifier->flag & FLAG_ZERO) == FLAG_ZERO)
			// 	printf("0\n");
			modifier->width = get_width(s, pa, &i);
			// printf("width = %d\n", modifier->width);
			modifier->accuracy = get_accuracy(s, &i, pa);
			// printf("accuracy = %d\n", modifier->accuracy);
			modifier->specifier = get_cpecifier(s, &i);
			//------------Проверка спецификаторов-------------
			// printf("specifier = %d\n", modifier->specifier);
			// if ((modifier->specifier & CPECIFIER_l) == CPECIFIER_l)
			// 	printf("l\n");
			// if ((modifier->specifier & CPECIFIER_ll) == CPECIFIER_ll)
			// 	printf("ll\n");
			// if ((modifier->specifier & CPECIFIER_h) == CPECIFIER_h)
			// 	printf("h\n");
			// if ((modifier->specifier & CPECIFIER_hh) == CPECIFIER_hh)
			// 	printf("hh\n");
			modifier->type = get_type(s, &i);
			// printf("type = %c\n", modifier->type);
			// if (s[i] == '\0')
			// 	return len;
			// str = make_str_out(modifier, pa);
			// ft_putstr_fd(str, 1); // Печатает в консоль аргумент
			// free(str);
		}
		if (s[i] == '\0')
			return len;
		str = make_str_out(modifier, pa);
		len = len + modifier->length;
		ft_putstr_fd(str, 1);
		free(str);
		i++;
	}
	free(modifier);
	return (len);
}
