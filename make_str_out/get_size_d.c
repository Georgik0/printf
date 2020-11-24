/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:37:08 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/20 16:37:09 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

int		get_size_d(long long int arg)
{
	int size;

	size = 1;
	if (arg == 0)
		return (size);
	while (arg != 0)
	{
		arg /= 10;
		size++;
	}
	return (size - 1);
}
