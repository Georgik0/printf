/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:34:20 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/21 18:35:30 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*make_malloc_x(int size)
{
	char	*str;

	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size] = '\0';
	return (str);
}

static void		fill_str_x(char *str, unsigned int n, int size)
{
	if (n % 16 == 10)
		str[size] = 'a';
	else if (n % 16 == 11)
		str[size] = 'b';
	else if (n % 16 == 12)
		str[size] = 'c';
	else if (n % 16 == 13)
		str[size] = 'd';
	else if (n % 16 == 14)
		str[size] = 'e';
	else if (n % 16 == 15)
		str[size] = 'f';
	else
		str[size] = n % 16 + '0';
}

char			*ft_itoa_x(unsigned int n)
{
	char	*str;
	int		size;

	size = ft_get_size_x(n);
	if (!(str = make_malloc_x(size)))
		return (NULL);
	size--;
	while (size >= 0)
	{
		fill_str_x(str, n, size);
		n = n / 16;
		size--;
	}
	return (str);
}
