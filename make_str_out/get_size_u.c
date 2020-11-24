/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:26:06 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/20 19:33:15 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

int		get_size_u(unsigned int arg)
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
