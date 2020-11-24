/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_space_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:42:57 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/20 17:48:37 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

char	*fill_space_d(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[size] = '\0';
	return (str);
}
