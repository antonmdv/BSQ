/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvalidity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:01:13 by amedvede          #+#    #+#             */
/*   Updated: 2018/08/15 22:18:26 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	    mapvalidity(list *l)
{
    Matrix	*mtrx;
	int		linelength;

	lineLength = 0;
	mtrx = malloc(sizeof(Matrix));
	mtrx->numOfLines = l->numLines;
	l = l->next;
	if (mtrx->numOfLines <= 0)
		return (0);
	mtrx->emptyChar = l->c;
	l = l->next;
	mtrx->obstacle = l->c;
	l = l->next;
	mtrx->full = l->c;
	l = l->next;
	while (l->next)
	{
		if (l->c != '\n' && l->c != mtrx->emptyChar &&
				l->c != mtrx->obstacle && l->c != mtrx->full)
			return (0);
		if (linelength == 0)
		{
			l = l->next;
			linelength = getlinelength(l);
		}
		else if (l->c == '\n')
		{
			l = l->next;
			if (linelength != getlinelength(l))
				return (0);
		}
		else
			l = l->next;
	}
	return (1);
}
