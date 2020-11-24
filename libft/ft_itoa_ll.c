/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:15:30 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/24 19:16:11 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ll(long long int n)
{
	char			*num;
	long long int	size;
	long long int	first;

	size = 1;
	first = n;
	if (n < 0)
		size++;
	while ((first /= 10) != 0)
		size++;
	if ((num = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	num[size] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		num[--size] = -(n % 10) + '0';
		n = n / -10 + 0 * first++;
	}
	while (--size >= first)
	{
		num[size] = n % 10 + '0';
		n = n / 10;
	}
	return (num);
}
