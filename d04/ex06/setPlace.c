/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:04:16 by pstringe          #+#    #+#             */
/*   Updated: 2019/04/02 20:06:31 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	return(parkingRow | (1 << pos));
}
