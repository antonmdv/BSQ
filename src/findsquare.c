/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findsquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:37:01 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 21:23:07 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

Square		*allocate(void)
{
	Square *sq;

	sq = malloc(sizeof(Square));
	sq->row = 0;
	sq->col = 0;
	sq->sideSize = 0;
	return (sq);
}

Square		*set_new_max(Square *sq, int side_size, int i, int j)
{
	sq->sideSize = side_size;
	sq->row = j;
	sq->col = i;
	return (sq);
}

Square		*findsquare(Matrix *mtrx)
{
	Square	*sq;
	int		i;
	int		j;

	j = 0;
	sq = allocate();
	while (j < mtrx->numOfLines)
	{
		i = 0;
		while (mtrx->field[j][i] != -1)
		{
			if (i == 0 || j == 0)
				mtrx->field[j][i] = mtrx->field[j][i];
			else if (mtrx->field[j][i] != 0)
			{
				mtrx->field[j][i] = 1 + getmin(mtrx->field[j][i - 1],
						mtrx->field[j - 1][i], mtrx->field[j - 1][i - 1]);
				if (mtrx->field[j][i] > sq->sideSize)
					sq = set_new_max(sq, mtrx->field[j][i], i, j);
			}
			i++;
		}
		j++;
	}
	return (sq);
}
