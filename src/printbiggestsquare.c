/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbiggestsquare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:50:50 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 21:19:59 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void		printbiggestsquare(Matrix *mtrx, Square *sq)
{
	int	i;
	int	j;

	j = 0;
	while (mtrx->field[j] != NULL)
	{
		i = 0;
		while (mtrx->field[j][i] != -1)
		{
			if (inrange(j, i, sq) == 1)
				put_char(mtrx->full);
			else
			{
				if (mtrx->field[j][i] == 0)
					put_char(mtrx->obstacle);
				else
					put_char(mtrx->emptyChar);
			}
			i++;
		}
		put_char('\n');
		j++;
	}
}
