/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:27:00 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/17 18:27:54 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TYPE_H
# define MY_TYPE_H

typedef struct	s_modifier
{
	int			flag;
	int			width;//ширина
	int			accuracy;//точность
	int			specifier;//спецификатор
	char		type;
	int			length;

}				t_modifier;

#endif
