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
	int			out;

	va_start(ap, format);
	if ((out = parser(format, &ap)) == -1)
		return (-1);
	str = va_arg(ap, char*);
	va_end(ap);
	return (out);
}
// Ошибка в %.p NULL
int main()
{
	// long int a = (long int)&s;
	// printf("%lx\n", a);
	// int *a = NULL;
	// int b = 12;
	// int c = 0x7ffe;
	// printf("%lx\n", c);
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

	// Вывод символа
	// printf("%d\n", printf("$%-4c\n", '\0'));
	// ft_printf("%d\n", ft_printf("$%-4c\n", '\0'));

	// printf("%d\n", printf("$%-3c$\n", '\0'));
	// printf("%d", printf("$%3c$", 0));
	// printf("\n");
	// ft_printf("%d", ft_printf("$%3c$", 0));

	// printf("$%*c$\n", -1, (char)NULL);
	// ft_printf("$%*c$\n", -1, (char)NULL);
	// printf("$%*c$\n", -3, '\a');
	// ft_printf("$%*c$\n", -3, '\a');

	// printf("%d\n", printf("$%*s$\n", 7, NULL));
	// ft_printf("%d\n", ft_printf("$%*s$\n", 7, NULL));

	// printf("указатель %d\n", b);
	// printf("указатель %p\n", a);
	// printf("указатель %-20lx$\n", c);
	// printf("c / 16 = %lx\n", c / 16);
	// printf("указатель %1p$\n", a);
	// ft_printf("указатель %1p$\n", a);

	// //-----------Для проверки----------
	// printf("%+5.0d$\n", 0)
	// ft_printf("%+5.0d$\n", 0);
	// //---------------------------------
	// printf("%019.*d$\n", -10, 123);
	// ft_printf("%019.*d$\n", -10, 123);

	// Смотрим поведение точности
	// printf("1     %07.*d$\n", 0, 123);
	// printf("2     %07d$\n", 123);
	// printf("3     %07.d$\n", 123);
	// printf("4     %7.d$\n", 123);
	// printf("5     %7.4d$\n", 123);
	// printf("6     %07.*d$\n", -2, 123);
	// printf("7     %07.*d$\n", 2, 123);
	// printf("8     $%-15.*d$\n", 6, 123);
	// printf("9     %07.*d$\n", -6, 123);

	// printf("%7.*d$\n", -1, 123436456);
	// ft_printf("%07.*d$\n", -1, 123);
	// printf("%07u$\n", 123436456);
	// ft_printf("%u$\n", 123436456);

	// printf("$%015.2X$\n", c);
	// ft_printf("$%015.2X$", c);

	// printf("%0*%$\n", 1);
	// ft_printf("%0*%$\n", 1);

	// printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	// ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');


	// printf("%d\n", printf("$%2c$\n", (char)6));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)6));
	// printf("%d\n", printf("$%2c$\n", (char)7));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)7));
	// printf("%d\n", printf("$%2c$\n", (char)8));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)8));
	// printf("%d\n", printf("$%2c$\n", (char)9));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)9));
	// printf("%d\n", printf("$%2c$\n", (char)10));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)10));
	// printf("%d\n", printf("$%2c$\n", (char)11));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)11));
	// printf("%d\n", printf("$%2c$\n", (char)12));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)12));
	// printf("%d\n", printf("$%2c$\n", (char)13));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)13));
	// printf("%d\n", printf("$%2c$\n", (char)15));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)15));
	// printf("%d\n", printf("$%2c$\n", (char)16));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)16));
	// printf("%d\n", printf("$%2c$\n", (char)17));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)17));
	// printf("%d\n", printf("$%2c$\n", (char)18));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)18));
	// printf("%d\n", printf("$%2c$\n", (char)19));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)19));
	// printf("%d\n", printf("$%2c$\n", (char)20));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)20));
	// printf("%d\n", printf("$%2c$\n", (char)21));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)21));
	// printf("%d\n", printf("$%2c$\n", (char)22));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)22));
	// printf("%d\n", printf("$%2c$\n", (char)23));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)23));
	// printf("%d\n", printf("$%2c$\n", (char)24));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)24));
	// printf("%d\n", printf("$%2c$\n", (char)25));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)25));
	// printf("%d\n", printf("$%2c$\n", (char)26));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)26));
	// printf("%d\n", printf("$%2c$\n", (char)27));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)27));
	// printf("%d\n", printf("$%2c$\n", (char)28));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)28));
	// printf("%d\n", printf("$%2c$\n", (char)29));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)29));
	// printf("%d\n", printf("$%2c$\n", (char)30));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)30));
	// printf("%d\n", printf("$%2c$\n", (char)31));
	// ft_printf("%d\n", ft_printf("$%2c$\n", (char)31));
	// printf("%-4c\n", '}');
	// ft_printf("%-4c", '}');

	ft_printf("%d\n", ft_printf("%.p\n", NULL));
	printf("%d\n", printf("%.p\n", NULL));

	// printf("%d\n", printf("%07d\n", -54));
	// ft_printf("%d\n", ft_printf("%07d\n", -54));

	// printf("%d\n", printf("%10.5d", -216));
	// ft_printf("%d\n", ft_printf("%10.5d", -216));

	// printf("%d\n", printf("%.0d\n", 0));
	// ft_printf("%d\n", ft_printf("%.0d\n", 0));

	// printf("%d\n", printf("$%.*s$\n", -3, "hello"));
	// ft_printf("%d\n", ft_printf("$%.*s$\n", -3, "hello"));

	// printf("%d\n", printf("%0*i$\n", -7, -54));
	// ft_printf("%d\n", ft_printf("%0*i$\n", -7, -54));

	// printf("%d\n", printf("%ld$\n", -2147483649));
	// ft_printf("%d\n", ft_printf("%d\n", -2147483649));

	// printf("%d\n", printf("%%u 0000042 == |%u|\n", 0000042));
	// ft_printf("%d\n", ft_printf("%%u 0000042 == |%u|\n", 0000042));

	// ft_printf("%%u 0000042 == |%u|\n", 0000042);
	// ft_printf("%%d 42 == |%d|\n", 42);

	// printf("%d\n", printf("%% *.5i 42 == |% *.5i|\n", 4, 42));
	// ft_printf("%d\n", ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42));

	// printf("          START CHECK\n\n");
    // printf("============================");
    // printf("\n        STRING CHECKING \n");
    // printf("===============1============\n");
	// printf("%d\n", printf("%----15c\n", 'd'));
	// printf("============================\n");
	// ft_printf("%d\n", ft_printf("%----15c\n", 'd'));
    // printf("===============2============\n");
	// printf("%d\n", printf("%-*.*s\n%-5.100s\n", 20, 5, "Hello", "World"));
    // printf("============================\n");
    // ft_printf("%d\n", ft_printf("%-*.*s\n%-5.100s\n", 20, 5,  "Hello", "World"));
    // printf("===============3============\n");
	// printf("%d\n", printf("%5.c\n", 'c'));
    // printf("============================\n");
    // ft_printf("%d\n", ft_printf("%5.c\n", 'c'));
    // printf("===============4============\n");
	// printf("%d\n", printf("%5.s\n", "Hello World"));
    // printf("============================\n");
    // ft_printf("%d\n", ft_printf("%5.s\n", "Hello World"));
    // printf("========END STRING CHECK========\n");
    // printf("============================");
	// printf("\n        VALUE CHECKING \n");
    // printf("============================\n");


    // printf("==============1=============\n");
	// printf("%d\n" ,printf("% 2d\n", 12));
	// printf("---------------------------\n");
	// ft_printf("%d\n", ft_printf("% 2d\n", 12));
	// printf("==============2=============\n");
	// printf("%d\n", printf("%12.10d\n", 20));
	// printf("---------------------------\n");
	// ft_printf("%d\n", ft_printf("%12.10d\n", 20));
	// printf("==============3=============\n");
	// // printf("%d\n", printf("%+3.5d\n", 12));
	// printf("---------------------------\n");
	// // ft_printf("%d\n", ft_printf("%+3.5d\n", 12));
	// printf("==============4=============\n");
	// // printf("%d\n", printf("%#.5x\n", 5));
	// printf("---------------------------\n");
	// // ft_printf("%d\n", ft_printf("%#.5x\n", 5));
	// printf("==============5=============\n");
	// printf("%d\n", printf("%.3x\n", 60));
    // printf("---------------------------\n");
    // ft_printf("%d\n", ft_printf("%.3x\n", 60));
    // printf("===============6===========\n");
	// printf("%d\n", printf("%#10.5X\n", 8655));
    // printf("---------------------------\n");
	// ft_printf("%d\n", ft_printf("%#10.5X\n", 8655));
    // printf("===============7===========\n");
    // // printf("%d\n", printf("%hhd\n", 78));
    // printf("---------------------------\n");
    // // ft_printf("%d\n", ft_printf("%hhd\n", 78));
    // printf("===============8===========\n");
    // // printf("%d\n", printf("%+030.15d\n", 889));
    // printf("---------------------------\n");
    // // ft_printf("%d\n", ft_printf("%+030.15d\n", 889));
    // printf("===============9===========\n");
    // printf("%d\n", printf("% 05d\n", 889));
    // printf("---------------------------\n");   // -> failed test
    // ft_printf("%d\n", ft_printf("% 05d\n", 889));
    // printf("==============10===========\n");
    // // printf("%d\n", printf("%#-5x\n", 0));
    // printf("---------------------------\n");
    // // ft_printf("%d\n", ft_printf("%#-5x\n", 0));// -> failed test || update -> not failed
    // printf("==============11===========\n");
    // // printf("%d\n", printf("%#x", 0));
    // printf("---------------------------\n");
    // // ft_printf("%d\n", ft_printf("%#x", 0));
    // printf("==============12===========\n");
    // // printf("%d\n", printf("%-#12.4x\n", 156));
    // printf("---------------------------\n");
    // // ft_printf("%d\n", ft_printf("%-#12.4x\n", 156));
    // printf("==============13===========\n");
	// // printf("%d\n", printf("%#010x\n", 27));
    // printf("---------------------------\n");
	// // ft_printf("%d\n", ft_printf("%#010x\n", 27));
    // printf("==============14===========\n");
    // // printf("%d\n", printf("%#10.5X\n", 8655));
    // printf("---------------------------\n");
    // // ft_printf("%d\n", ft_printf("%#10.5X\n", 8655));
    // printf("==============15===========\n");
    // printf("%d\n", printf("%.3x\n", 60));
    // printf("---------------------------\n");
    // ft_printf("%d\n", ft_printf("%.3x\n", 60));
    // printf("==============16===========\n");
    // // printf("%d\n", printf("%3hhi\n", 'b'));
    // ft_printf("--------------------------------\n");
    // // ft_printf("%d\n", ft_printf("%3hhi\n", 'b'));
    // printf("==============17===========\n");
    // printf("%d\n", printf("% 5d\n", 89));
    // ft_printf("------------------------\n");
    // ft_printf("%d\n", ft_printf("% 5d\n", 89));
    // printf("==============18===========\n");
    // // printf("%d\n", printf("%#010x\n", 87));
    // ft_printf("------------------------\n");
    // // ft_printf("%d\n", ft_printf("%#010x\n", 87));
    // printf("==============19===========\n");
    // printf("%d\n", printf("%010x\n", 87));
    // ft_printf("------------------------\n");
    // ft_printf("%d\n", ft_printf("%010x\n", 87));
    // printf("==============20===========\n");
    // // printf("%d\n", printf("%#3x\n", 18));
    // ft_printf("------------------------\n");
    // // ft_printf("%d\n", ft_printf("%#3x\n", 18));
    // printf("==============21===========\n");
    // // printf("%d\n", printf("%+05d\n", 889));
    // printf("---------------------------\n");   // -> failed test
    // // ft_printf("%d\n", ft_printf("%+05d\n", 889));
    // printf("==============22===========\n");
    // // printf("Hello %n\n %d  %hhi\n", x, 67890, 'i');
    // printf("---------------------------\n");
    // // ft_printf("Hello %n\n %d  %hhi\n", x, 67890, 'i');
    // printf("==============23===========\n");
    // // printf("%d\n", printf("%-30.p\n", 0));
    // printf("---------------------------\n");
    // ft_printf("%d\n", ft_printf("%-30.p\n", 0));
    // printf("==============25===========\n");
    // // printf("%*d\n %-s\n%-#012x\n", -10, 5, "Hello", 89);
    // printf("---------------------------\n");
    // // ft_printf("%*d\n %-s\n%-#012x\n", -10, 5, "Hello", 89);
    // printf("==============26===========\n");
    // printf("END CHECK");
	// // ft_printf("%d", ft_printf("%.*s", -3, "hello"));

	return (0);
}
