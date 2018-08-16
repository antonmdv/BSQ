/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforminput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:52:16 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 21:24:20 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

Matrix		*allocate_matrix(list *l)
{
	Matrix *mtrx;

	mtrx = malloc(sizeof(Matrix));
	mtrx->numOfLines = l->numLines;
	l = l->next;
	mtrx->emptyChar = l->c;
	l = l->next;
	mtrx->obstacle = l->c;
	l = l->next;
	mtrx->full = l->c;
	mtrx->field = (int **)malloc((sizeof(int **) * mtrx->numOfLines) + 1);
	mtrx->field[mtrx->numOfLines] = NULL;
	return (mtrx);
}

list		*skip_to_valid(list *l)
{
	int i;

	i = 0;
	while (i < 4)
	{
		l = l->next;
		i++;
	}
	return (l);
}

Matrix		*allocate_new_line_in_mtrx(Matrix *mtrx, list *l, int row)
{
	int linelength;

	linelength = getlinelength(l);
	mtrx->field[row] = (int *)malloc((sizeof(int) * linelength) + 1);
	if (l->c == mtrx->obstacle)
		mtrx->field[row][0] = 0;
	else
		mtrx->field[row][0] = 1;
	mtrx->field[row][linelength] = -1;
	return (mtrx);
}

Matrix		*transform(list *l)
{
	Matrix	*mtrx;
	int		row;
	int		col;

	row = -1;
	mtrx = allocate_matrix(l);
	l = skip_to_valid(l);
	while (l->next)
	{
		if (l->c == '\n')
		{
			l = l->next;
			col = 0;
			mtrx = allocate_new_line_in_mtrx(mtrx, l, ++row);
		}
		else
		{
			if (l->c == mtrx->obstacle)
				mtrx->field[row][++col] = 0;
			else
				mtrx->field[row][++col] = 1;
		}
		l = l->next;
	}
	return (mtrx);
}
