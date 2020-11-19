/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:58:43 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/13 17:59:53 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*str;

	va_start(ap, format);
	if (parser(format, &ap) == -1)
		return (0);
	str = va_arg(ap, char*);
	va_end(ap);
	return (0);
}

int main()
{
	// int *a = NULL;
	// int b = 12;
	// long int c = 0x7ffeecbbb8ec;
	// a = &b;
	// printf("%+04d\n", 12);
	// printf("%d\n", FLAG_PLUS);
	// printf("%00*d\n", 10, -13542);
	// printf("%03d\n", -1);
	//printf("%0*d\n", 5, 1);
	//ft_printf("text before   %41234.1234hhi", 12354, 1012345);
	// printf("%3c\n", 'a');
	// printf("%3s\n", "asdasd");
	// printf("Символ = %10c    Еще символ = %-5c      Еще символ = %c     Еще символ = %c     Еще символ = %3c\n", 'a', 'b', 'c', 'd', 'e');
	// ft_printf("Символ = %10c    Еще символ = %-5c      Еще символ = %c     Еще символ = %c     Еще символ = %3c", 'a', 'b', 'c', 'd', 'e');
	// ft_printf("test1 = %10c    test2 = %5c      test3 = %c     test4 = %#c     test5 = %3c", 'a', 'b', 'c', 'd', 'e');
	// ft_printf("test = %c", 'a');
	// printf("$%-4s$\n", "123");
	// ft_printf("$%-4s$", "123");
	// printf("указатель %d\n", b);
	// printf("указатель %p\n", a);
	// printf("указатель %-20lx$\n", c);
	// printf("c / 16 = %lx\n", c / 16);
	// printf("указатель %p$\n", a);
	// ft_printf("указатель %1p$\n", a);
	return (0);
}
