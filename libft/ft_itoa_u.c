/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:03 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/20 20:01:05 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_u(unsigned int n)
{
	char			*num;
	unsigned int	size;
	unsigned int	first;

	num = NULL;
	size = 1;
	first = n;
	while ((first /= 10) != 0)
		size++;
	if ((num = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	num[size] = '\0';
	size--;
	while (size != 0)
	{
		num[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	num[0] = n % 10 + '0';
	return (num);
}
