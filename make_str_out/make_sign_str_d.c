/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sign_str_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:56:17 by skitsch           #+#    #+#             */
/*   Updated: 2020/12/02 16:56:19 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"

char		*make_sign_str(t_modifier *modifier, int arg)
{
	char	*sign;

	if (!(sign = (char *)malloc(2 * sizeof(char))))
		return (NULL);
	if (arg < 0)
		sign[0] = '-';
	else if (((modifier->flag & FLAG_PLUS) == FLAG_PLUS) && arg > 0)
		sign[0] = '+';
	else
	{
		free(sign);
		return (NULL);
	}
	sign[1] = '\0';
	return (sign);
}
